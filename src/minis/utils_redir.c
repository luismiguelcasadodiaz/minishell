/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:03:18 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/02 17:40:30 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_error.h"

static int	pipe_set_up_middle_fork(t_exec *a)
{
	int	i;
	int	who;

	i = a->exe_cmds;
	who = a->cmds[i]->pid;
	my_close(who, &a->cmds[i]->pipe[READ], __func__, __LINE__);
	if (dup2(a->cmds[i - 1]->pipe[READ], STDIN_FILENO) == -1)
		return (ft_error_print_ret(errno, __func__, __LINE__));
	my_close(who, &a->cmds[i - 1]->pipe[READ], __func__, __LINE__);
	if (dup2(a->cmds[i]->pipe[WRITE], STDOUT_FILENO) == -1)
		return (ft_error_print_ret(errno, __func__, __LINE__));
	my_close(who, &a->cmds[i]->pipe[WRITE], __func__, __LINE__);
	return (0);
}

static int	pipe_set_up(t_exec *a)
{
	int	i;
	int	who;

	i = a->exe_cmds;
	who = a->cmds[i]->pid;
	if (a->max_cmds > 1)
	{
		if (i == 0)
		{
			my_close(who, &a->cmds[i]->pipe[READ], __func__, __LINE__);
			if (dup2(a->cmds[i]->pipe[WRITE], STDOUT_FILENO) == -1)
				return (ft_error_print_ret(errno, __func__, __LINE__));
			my_close(who, &a->cmds[i]->pipe[WRITE], __func__, __LINE__);
		}
		else if (i == a->max_cmds -1)
		{
			if (dup2(a->cmds[i - 1]->pipe[READ], STDIN_FILENO) == -1)
				return (ft_error_print_ret(errno, __func__, __LINE__));
			my_close(who, &a->cmds[i - 1]->pipe[READ], __func__, __LINE__);
		}
		else
			return (pipe_set_up_middle_fork(a));
	}
	return (0);
}

static int	one_command_builtin(t_exec *a, char **env)
{
	if (a->cmds[a->exe_cmds]->redirect)
	{
		if (open_redirections(a, env))
			return (1);
		duplicate_last_redirections(a);
		close_unused(a);
	}
	return (0);
}

static int	handle_redirections_and_pipes(t_exec *a, char **env)
{
	if (a->cmds[a->exe_cmds]->redirect)
	{
		if (open_redirections(a, env))
			return (1);
		pipe_set_up(a);
		duplicate_last_redirections(a);
		close_unused(a);
	}
	else
		pipe_set_up(a);
	return (0);
}

int	minis_execute_open_files(t_exec *a, char **env)
{
	int	i;

	if ((a->max_cmds == 1 && builtin_check(a->cmds[0]->flg[0]) == 1))
		return (one_command_builtin(a, env));
	else
	{
		if (a->cmds[0]->flg[0] != NULL)
		{
			my_close(0, &a->fd_i, __func__, __LINE__);
			my_close(0, &a->fd_o, __func__, __LINE__);
		}
		i = 0;
		while (i < a->exe_cmds - 1)
			my_close(0, &a->cmds[i++]->pipe[READ], __func__, __LINE__);
		return (handle_redirections_and_pipes(a, env));
	}
	return (0);
}

//looks for last (*ll) input redirection in first command
//if exists an input redirection duplicate it
//looks for last (*lg) output redirection in last command and open it
/*
int	minis_execute_open_files(t_exec *a, char **env)
{
	int	i;

	if ((a->max_cmds == 1 && builtin_check(a->cmds[0]->flg[0]) == 1))
		return (one_command_builtin(a, env));
	else
	{
		if (a->cmds[0]->flg[0] != NULL)
		{
			my_close(0, &a->fd_i, __func__, __LINE__);
			my_close(0, &a->fd_o, __func__, __LINE__);
		}
		i = 0;
		while (i < a->exe_cmds - 1)
			my_close(0, &a->cmds[i++]->pipe[READ], __func__, __LINE__);
		if (a->cmds[a->exe_cmds]->redirect)
		{
			if (open_redirections(a, env))
				return (1);
			pipe_set_up(a);
			duplicate_last_redirections(a);
			close_unused(a);
		}
		else
			pipe_set_up(a);
	}
	return (0);
}
*/