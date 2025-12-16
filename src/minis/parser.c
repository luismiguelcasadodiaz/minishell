/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:29:50 by maria-nm          #+#    #+#             */
/*   Updated: 2025/12/16 20:28:02 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_redirect(t_exec *inter, t_lex **lexer)
{
	t_lex	*list;
	int		i;

	list = *lexer;
	i = 0;
	while (i < inter->max_cmds && list != NULL)
	{
		while (list && list->token != PIPE)
			list = make_sublist(inter->cmds[i], list, lexer);
		if (list)
			list = list->next;
		i++;
	}
	return (0);
}

int	parser(t_exec *inter, t_lex **lexer)
{
	if (!lexer)
		return (0);
	if (check_syntax_error(*lexer) == SYNTAX_ERR)
		return (lex_lstclear(lexer), SYNTAX_ERR);
	*inter = exec_create(count_cmd(lexer));
	if (make_exec(inter, lexer) != 0)
		return (1);
	if (make_redirect(inter, lexer) != 0)
		return (1);
	return (0);
}
