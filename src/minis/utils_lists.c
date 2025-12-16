/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:43:08 by maria-nm          #+#    #+#             */
/*   Updated: 2024/04/29 13:33:18 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lex	*lex_lstnew(void)
{
	t_lex	*node;

	node = malloc(sizeof(t_lex));
	if (!node)
		return (NULL);
	node->word = NULL;
	node->token = NONE;
	node->prev = NULL;
	node->next = NULL;
	node->path = NULL;
	node->token_free = 0;
	node->fd = -1;
	node->here_pipe[READ] = -1;
	node->here_pipe[WRITE] = -1;
	node->is_w = -1;
	node->is_r = -1;
	node->is_exp = 0;
	node->f_size = -1;
	return (node);
}

void	lex_lstadd_back(t_lex **lst, t_lex *new)
{
	t_lex	*last;

	if (*lst)
	{
		last = lex_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
	else
		*lst = new;
}

void	lex_lstclear(t_lex **lst)
{
	t_lex	*nxt;
	t_lex	*aux;

	aux = *lst;
	while (aux)
	{
		nxt = aux->next;
		if (aux->word)
			free(aux->word);
		free(aux);
		aux = nxt;
	}
	*lst = NULL;
}

int	lex_lstsize(t_lex *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_lex	*lex_lstlast(t_lex *lst)
{
	t_lex	*node;

	if (!lst)
		return (0);
	node = lst;
	while ((node->next))
		node = node->next;
	return (node);
}
