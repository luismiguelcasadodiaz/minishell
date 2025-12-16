/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checks2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:18:51 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/14 16:19:14 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lex	*create_and_update_node(char *n_w, t_lex **tmp, t_lex **lexer)
{
	t_lex	*new_node;

	new_node = lex_lstnew();
	if (!new_node)
		return (free(n_w), NULL);
	change_new_node(new_node, n_w, *tmp);
	update_list_links(new_node, *tmp, lexer);
	free_tmp(*tmp);
	return (new_node);
}

static int	process_node(t_lex **tmp, t_lex **lexer)
{
	char	*new_word;
	t_lex	*new_node;	

	new_word = NULL;
	if (check_str_list(*tmp) == 1)
	{
		new_word = make_new_word(*tmp, (*tmp)->next);
		if (!new_word)
			return (-1);
		new_node = create_and_update_node(new_word, tmp, lexer);
		if (!new_node)
			return (-1);
		*tmp = new_node;
	}
	else
		*tmp = (*tmp)->next;
	return (0);
}

int	check_list(t_lex **lexer)
{
	t_lex	*tmp;

	tmp = *lexer;
	if (*lexer == NULL || (*lexer)->next == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		if (process_node(&tmp, lexer) == -1)
			return (-1);
	}
	return (0);
}

/* SUSTITUIDA POR las static y utils_check3.c
int	check_list(t_lex **lexer)
{
	t_lex	*tmp;
	char	*new_word;
	t_lex	*new_node;

	tmp = *lexer;
	new_word = NULL;
	if (*lexer == NULL || (*lexer)->next == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		if (check_str_list(tmp) == 1)
		{
			new_word = make_new_word(tmp, tmp->next);
			if (!new_word)
				return (-1);
			new_node = lex_lstnew();
			if (!new_node)
				return (free(new_word), -1);
			change_new_node(new_node, new_word, tmp);
			if (tmp->prev != NULL)
				tmp->prev->next = new_node;
			else
				*lexer = new_node;
			if (tmp->next->next != NULL)
				tmp->next->next->prev = new_node;
			free_tmp(tmp);
			tmp = new_node;
		}
		else
			tmp = tmp->next;
	}
	return (0);
}
*/