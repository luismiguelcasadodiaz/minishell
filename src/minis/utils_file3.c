/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:55:18 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/01 00:53:10 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_pipes(t_exec *pinter, int *error)
{
	if (pipe(pinter->cmds[pinter->exe_cmds]->pipe) < 0)
	{
		*error = errno;
		ft_error_print(*error, __func__, __LINE__);
		return (*error);
	}
	return (0);
}

void	close_exe_cmds_pipes(t_exec *a, const char *f, int l)
{
	int	who;
	int	i;

	i = a->exe_cmds;
	who = a->cmds[i]->pid;
	if (!(a->max_cmds == 1 && builtin_check(a->cmds[0]->flg[0]) == 1))
	{
		my_close(who, &a->cmds[i]->pipe[READ], f, l);
		my_close(who, &a->cmds[i]->pipe[WRITE], f, l);
	}
}

int	open_pipes_here(t_lex *redir, int *error)
{
	if (pipe(redir->here_pipe) < 0)
	{
		*error = errno;
		ft_error_print(*error, __func__, __LINE__);
		return (*error);
	}
	return (0);
}

int	is_directory(const char *path)
{
	struct stat	statbuf;

	if (lstat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

// changes the meaning of access()' result for code readibility
int	have_access(const char *path, int mode)
{
	int	result;

	result = access(path, mode);
	if (result == -1)
		result = 0;
	else
		result = 1;
	return (result);
}
