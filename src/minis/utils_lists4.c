/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:36:00 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/16 14:36:20 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lex	*remove_only_node(t_lex *current, t_lex **list)
{
	free(current);
	*list = NULL;
	return (NULL);
}

static t_lex	*remove_first_node(t_lex *current, t_lex **list)
{
	t_lex	*next_node;

	next_node = current->next;
	*list = next_node;
	if (next_node != NULL)
	{
		next_node->prev = NULL;
	}
	free(current);
	return (next_node);
}

static t_lex	*remove_last_node(t_lex *current)
{
	t_lex	*prev_node;

	prev_node = current->prev;
	prev_node->next = NULL;
	free(current);
	return (NULL);
}

static t_lex	*remove_middle_node(t_lex *current)
{
	t_lex	*next_node;
	t_lex	*prev_node;

	next_node = current->next;
	prev_node = current->prev;
	if (prev_node != NULL && next_node != NULL)
	{
		prev_node->next = next_node;
		next_node->prev = prev_node;
	}
	free(current);
	return (next_node);
}

t_lex	*remove_node(t_lex *current, t_lex **list)
{
	if (current == NULL)
		return (NULL);
	if (current->prev == NULL && current->next == NULL)
	{
		return (remove_only_node(current, list));
	}
	if (current->prev == NULL)
	{
		return (remove_first_node(current, list));
	}
	if (current->next == NULL)
	{
		return (remove_last_node(current));
	}
	return (remove_middle_node(current));
}
/*
t_lex	*remove_node(t_lex *current, t_lex **list)
{
	t_lex	*next_node;
	t_lex	*prev_node;

	if (current == NULL)
		return (NULL);
	next_node = current->next;
	prev_node = current->prev;
	if (prev_node == NULL && next_node == NULL)
	{
		free(current);
		*list = NULL;
		return (NULL);
	}
	if (prev_node == NULL)
	{
		if (next_node != NULL)
		{
			*list = (*list)->next;
			next_node->prev = NULL;
		}
		free(current);
		return (next_node);
	}
	if (next_node == NULL)
	{
		prev_node->next = NULL;
		free(current);
		return (NULL);
	}
	prev_node->next = next_node;
	next_node->prev = prev_node;
	free(current);
	return (next_node);
}
*/