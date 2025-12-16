/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:38:40 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/14 12:39:09 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lex_print_lst(t_lex *lst)
{
	t_lex	*nxt;
	t_lex	*aux;

	aux = lst;
	while (aux)
	{
		nxt = aux->next;
		ft_printf("[%d]>%s<\n", aux->token, aux->word);
		aux = nxt;
	}
}

static void	delete_current_node(t_lex **lexer, t_lex **current, t_lex **prev)
{
	t_lex	*node_to_delete;

	node_to_delete = *current;
	if (*prev == NULL)
	{
		*lexer = (*current)->next;
		if (*lexer != NULL)
			(*lexer)->prev = NULL;
		*current = *lexer;
	}
	else
	{
		(*prev)->next = (*current)->next;
		if ((*current)->next != NULL)
			(*current)->next->prev = *prev;
		*current = (*prev)->next;
	}
	free(node_to_delete->word);
	free(node_to_delete);
}

void	delete_white_space(t_lex **lexer)
{
	t_lex	*current;
	t_lex	*prev;

	current = *lexer;
	prev = NULL;
	if (*lexer == NULL)
		return ;
	while (current != NULL)
	{
		if (current->token == WHITE_SPACE)
		{
			delete_current_node(lexer, &current, &prev);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

/*divido en las 2 funciones anteriores
void	delete_white_space(t_lex **lexer)
{
	t_lex	*current;
	t_lex	*prev;

	current = *lexer;
	prev = NULL;
	if (*lexer == NULL)
		return ;
	while (current != NULL)
	{
		if (current->token == WHITE_SPACE)
		{
			if (prev == NULL)
			{
				*lexer = current->next;
				if (*lexer != NULL)
					(*lexer)->prev = NULL;
				free(current->word);
				free(current);
				current = *lexer;
			}
			else
			{
				prev->next = current->next;
				if (current->next != NULL)
					current->next->prev = prev;
				free(current->word);
				free(current);
				current = prev->next;
			}
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}
*/