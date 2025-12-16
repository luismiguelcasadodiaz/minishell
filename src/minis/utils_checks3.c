/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checks3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:34:26 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/15 11:50:12 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_str_list(t_lex *tmp)
{
	if ((tmp->token == STRING || tmp->token == STRING_ONE_Q || \
					tmp->token == STRING_TWO_Q) && \
				(tmp->next->token == STRING || \
						tmp->next->token == STRING_ONE_Q || \
						tmp->next->token == STRING_TWO_Q))
		return (1);
	return (0);
}

void	change_new_node(t_lex *n, char *new_word, t_lex *tmp)
{
	n->word = new_word;
	n->token = STRING;
	n->prev = tmp->prev;
	n->next = tmp->next->next;
}

void	free_tmp(t_lex *tmp)
{
	t_lex	*next;

	next = tmp->next;
	free(tmp->word);
	free(next->word);
	free(next);
	free(tmp);
}

void	update_list_links(t_lex *new_node, t_lex *tmp, t_lex **lexer)
{
	if (tmp->prev != NULL)
		tmp->prev->next = new_node;
	else
		*lexer = new_node;
	if (tmp->next->next != NULL)
		tmp->next->next->prev = new_node;
}
