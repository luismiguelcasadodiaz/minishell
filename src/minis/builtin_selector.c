/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:06:24 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/01 00:47:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"
#include <signal.h>

static int	last_command_status(t_exec *a)
{
	int	i;
	int	j;
	int	exited_pid;
	int	error;
	int	status;

	i = 0;
	while (i < a->exe_cmds)
	{
		exited_pid = wait(&error);
		if (WIFEXITED(error))
			status = WEXITSTATUS(error);
		else if (WIFSIGNALED(error))
			status = 128 + WTERMSIG(error);
		else if (WIFSTOPPED(error))
			kill(exited_pid, SIGTTIN);
		j = -1;
		while (++j < a->exe_cmds)
			if (a->cmds[j]->pid == exited_pid)
				a->cmds[j]->exit_status = status;
		i++;
	}
	return (exit_status(1, a->cmds[a->exe_cmds -1]->exit_status));
}

/******************************************************************************/
/**
   @file builtin_selector.c
   @brief execute_lmcd() returns loops thru cmds in inter strucuture.

   Launch in parallel all comands
   creates a pipe for each comand.
   Stores pipe's fd in the commands variables for that purpouse
   If the command is not executable the child does not process redirections

	verifies that stdin and stdput are correct before returning to readline
   @param[in]  *vars: an enviromental variable wiht this format:
            NAME=VALUE

   @details
   Set into interface strucutre PWD and PATH to use it in the command
   validation made by arg_ok.

   Executes the command

   @returns
   exit status of last executed command

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/

static void	exec_father_or_child(t_exec *a, t_env **env)
{
	if (a->cmds[a->exe_cmds]->pid == 0)
	{
		execute_one_command(*a, env);
		a->exe_cmds = a->max_cmds;
	}
	else
	{
		if ((a->max_cmds > 1) && (a->exe_cmds < (a->max_cmds -1)))
			my_close(0, &a->cmds[a->exe_cmds]->pipe[WRITE], __func__, __LINE__);
	}
}

static int	loop_cmds(t_exec *a, t_env **env)
{
	int	i;

	while (a->exe_cmds < a->max_cmds)
	{
		if ((a->max_cmds > 1) && (a->exe_cmds < (a->max_cmds -1)) \
			&& open_pipes(a, &i))
			return (exit_status(1, i));
		a->cmds[a->exe_cmds]->pid = fork();
		if (a->cmds[a->exe_cmds]->pid < 0)
			return (exit_status(1, \
			ft_error_print_ret(errno, __func__, __LINE__)));
		exec_father_or_child(a, env);
		a->exe_cmds++;
	}
	i = 0;
	while (i < a->max_cmds -1)
		my_close(0, &a->cmds[i++]->pipe[READ], __func__, __LINE__);
	return (0);
}

static int	builtin_selector_error_check(t_exec *a, int error)
{
	if (error)
		return (error);
	if (a->max_cmds != 0)
		return (exit_status(1, last_command_status(a)));
	else
		return (exit_status(0, 0));
}

int	builtin_selector(t_exec *a, t_env **env)
{
	int	i;
	int	error;

	i = a->exe_cmds;
	if (a->max_cmds == 1 && builtin_check(a->cmds[0]->flg[0]) == 1)
	{
		if (minis_execute_open_files(a, (*env)->env))
			return (1);
		exit_status(1, builtin_exe(a->cmds[i]->flg[0], a->cmds[i]->flg, *env));
		if (a->cmds[i]->fd_ll != -1)
			my_close(0, &a->cmds[i]->fd_ll, __func__, __LINE__);
		return (exit_status(0, 0));
	}
	else if (a->max_cmds == 1 && (a->cmds[0]->flg[0] == NULL) \
	&& a->cmds[i]->redirect)
		return (exit_status(1, minis_execute_open_files(a, (*env)->env)));
	else if (a->max_cmds == 1 && *a->cmds[i]->flg[0] == '\0' \
					&& a->cmds[i]->is_exp_one == 1)
		return (exit_status(1, 0));
	else if (a->max_cmds == 1 && *a->cmds[i]->flg[0] == '\0')
		return (ret_perror(127, a->cmds[i]->flg[0], ": command not found"));
	else if (a->max_cmds == 1 && a->cmds[i]->is_d)
		return (ret_perror(126, a->cmds[i]->flg[0], ": Is a directory"));
	error = loop_cmds(a, env);
	return (builtin_selector_error_check(a, error));
}
