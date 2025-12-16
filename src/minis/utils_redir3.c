/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:50:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/04 18:50:38 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_error.h"

int	ret_perror(int e_num, char *msg1, char *msg2)
{
	my_perror(msg1, msg2);
	return (exit_status(1, e_num));
}

void	treat_last_redir(t_exec *pinter)
{
	int		i;

	i = pinter->exe_cmds;
	if (pinter->cmds[i]->ll != NULL)
	{
		if (pinter->cmds[i]->ll->fd != -1)
			pinter->cmds[i]->fd_ll = pinter->cmds[i]->ll->fd;
		else
			pinter->cmds[i]->fd_ll = pinter->cmds[i]->ll->here_pipe[READ];
	}
	if (pinter->cmds[i]->lg != NULL)
		pinter->cmds[i]->fd_lg = pinter->cmds[i]->lg->fd;
}

/*
void	register_current_redir(t_exec *pinter, t_token token, t_lex *redir)
{
	int		i;

	i = pinter->exe_cmds;
	if (token == LESS)
	{
		if (pinter->cmds[i]->ll)
			my_close(0, &pinter->cmds[i]->ll->fd, __func__, __LINE__);
		pinter->cmds[i]->ll = redir;
	}
	else if (token == LESS_LESS)
	{
		if (pinter->cmds[i]->lhd)
		{
			my_close(0, &pinter->cmds[i]->lhd->here_pipe[READ], __func__, __LINE__);
			//my_close(0, &pinter->cmds[i]->lhd->here_pipe[WRITE], __func__, __LINE__);
		}
		pinter->cmds[i]->lhd = redir;
	}
	else if ((token == GREAT) || (token == GREAT_GREAT))
	{
		if (pinter->cmds[i]->lg)
			my_close(0, &pinter->cmds[i]->lg->fd, __func__, __LINE__);
		pinter->cmds[i]->lg = redir;
	}
}
*/

//loops redirection list opening each file accordingly
//each time it opens a redirection register it as the last one cause
//we need to preserve fd of the last redirection.
int	open_redirections(t_exec *pinter, char **env)
{
	t_token	token;
	t_lex	*redir;
	int		i;

	i = pinter->exe_cmds;
	redir = pinter->cmds[i]->redirect;
	while (redir)
	{
		if (token_is_any_string(redir->token))
		{
			token = redir->prev->token;
			if (open_file_properly(redir, token, env))
				return (1);
			if ((token == LESS) || (token == LESS_LESS))
                pinter->cmds[i]->ll = redir;
            else if ((token == GREAT) || (token == GREAT_GREAT))
                pinter->cmds[i]->lg = redir;

		}
		redir = redir ->next;
	}
	treat_last_redir(pinter);
	return (0);
}
