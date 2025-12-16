/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:14:41 by luicasad          #+#    #+#             */
/*   Updated: 2024/06/25 00:30:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	exit_perr(int e_num, char *msg1, char *msg2)
{
	my_perror(msg1, msg2);
	return (exit_status(1, e_num));
}

static void	execve_error_check(t_exec a, int numerr)
{
	if ((numerr == 2) || (numerr == 14))
	{
		if (a.cmds[a.exe_cmds]->cli[0] == '/')
			exit_perr(127, a.cmds[a.exe_cmds]->cli, \
			": No such file or directory");
		exit_perr(127, a.cmds[a.exe_cmds]->cli, ": command not found");
	}
	if (numerr == 13)
		exit_perr(126, a.cmds[a.exe_cmds]->cli, ": permission denied");
	exit (exit_status(0, 0));
}

void	execute_one_command(t_exec a, t_env **env)
{
	int		numerr;
	char	**args;

	if (minis_execute_open_files(&a, (*env)->env))
		exit (1);
	if (!a.cmds[a.exe_cmds]->flg)
		exit (1);
	if (a.cmds[a.exe_cmds]->flg[0] == NULL)
		exit (0);
	args = a.cmds[a.exe_cmds]->flg;
	if (builtin_check(args[0]) == 1)
	{
		exit_status(1, builtin_exe(args[0], args, *env));
		if (a.cmds[a.exe_cmds]->fd_ll != -1)
			my_close(0, &a.cmds[a.exe_cmds]->fd_ll, __func__, __LINE__);
		exit (exit_status(0, 0));
	}
	if (a.path == NULL)
		exit_perr(127, a.cmds[a.exe_cmds]->cli, ": No such file or directory");
	if (*a.cmds[a.exe_cmds]->flg[0] == '\0')
		exit (0);
	execve(a.cmds[a.exe_cmds]->cmd, a.cmds[a.exe_cmds]->flg, (*env)->env);
	numerr = errno;
	execve_error_check(a, numerr);
}
