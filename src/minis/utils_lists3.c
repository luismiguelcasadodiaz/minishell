/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:21:52 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/15 15:22:13 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lex	*process_null_prev(t_ecmd *cmd, t_lex *current, t_lex **list)
{
	cmd->redirect = current;
	while (current && current->token != PIPE)
		current = current->next;
	if (current != NULL)
	{
		current->prev->next = NULL;
		current->prev = NULL;
	}
	*list = current;
	return (current);
}

static t_lex	*process_non_null_prev(t_ecmd *cmd, t_lex *current)
{
	t_lex	*pipe1;

	pipe1 = current->prev;
	cmd->redirect = current;
	cmd->redirect->prev = NULL;
	while (current && current->token != PIPE)
		current = current->next;
	if (current != NULL)
	{
		pipe1->next = current;
		current->prev->next = NULL;
		current->prev = pipe1;
	}
	else
		pipe1->next = current;
	return (current);
}

t_lex	*make_sublist(t_ecmd *cmd, t_lex *node, t_lex **list)
{
	t_lex	*current;

	if (node == NULL)
		return (NULL);
	current = node;
	if (current->prev == NULL)
	{
		return (process_null_prev(cmd, current, list));
	}
	else
	{
		return (process_non_null_prev(cmd, current));
	}
	return (current);
}

/*
t_lex	*make_sublist(t_ecmd *cmd, t_lex *node, t_lex **list)
{
	t_lex	*current;
	t_lex	*pipe1;

	if (node == NULL)
		return (NULL);
	current = node;
	if (current->prev == NULL)
	{
		cmd->redirect = node;
		while (current && current->token != PIPE)
			current = current->next;
		if (current != NULL)
		{
			current->prev->next = NULL;
			current->prev = NULL;
		}
		*list = current;
	}
	else
	{
		pipe1 = node->prev;
		cmd->redirect = node;
		cmd->redirect->prev = NULL;
		while (current && current->token != PIPE)
			current = current->next;
		if (current != NULL)
		{
			pipe1->next = current;
			current->prev->next = NULL;
			current->prev = pipe1;
		}
		else
			pipe1->next = current;
	}
	return (current);
}
*/