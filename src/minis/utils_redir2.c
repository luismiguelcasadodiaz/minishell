/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:03:18 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/02 17:36:44 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_error.h"

// gets pointer to STRING nodes with last redirection
//
void	duplicate_last_redirections(t_exec *a)
{
	int		i;

	i = a->exe_cmds;
	if (a->cmds[i]->flg[0] && (*a->cmds[i]->flg[0] != '\0') \
	&& (a->cmds[i]->fd_ll != -1))
	{
		if ((dup2(a->cmds[i]->fd_ll, STDIN_FILENO) == -1))
			ft_error_exit(ERR007, __func__, __LINE__);
		my_close(0, &a->cmds[i]->fd_ll, __func__, __LINE__);
	}
	if (a->cmds[i]->flg[0] && (*a->cmds[i]->flg[0] != '\0') \
	&& (a->cmds[i]->fd_lg != -1))
	{
		if ((dup2(a->cmds[i]->fd_lg, STDOUT_FILENO) == -1))
			ft_error_exit(ERR007, __func__, __LINE__);
		my_close(0, &a->cmds[i]->fd_lg, __func__, __LINE__);
		//if (a->max_cmds > 1)
		//{
		//	my_close(0, &a->cmds[i]->pipe[READ], __func__, __LINE__);
		//	my_close(0, &a->cmds[i]->pipe[WRITE], __func__, __LINE__);
		//}
	}
}

void	close_unused(t_exec *a)
{
	t_lex	*redir;
	int		i;

	i = a->exe_cmds;
	redir = a->cmds[i]->redirect;
	while (redir)
	{
		if (token_is_any_string(redir->token)
			&& redir != a->cmds[i]->ll
			&& redir != a->cmds[i]->lg)
		{
			if (redir->fd != -1)
				my_close(0, &redir->fd, __func__, __LINE__);
			if (redir->here_pipe[WRITE] != -1)
			{
				my_close(0, &redir->here_pipe[WRITE], __func__, __LINE__);
				my_close(0, &redir->here_pipe[READ], __func__, __LINE__);
			}
		}
		redir = redir ->next;
	}
}
