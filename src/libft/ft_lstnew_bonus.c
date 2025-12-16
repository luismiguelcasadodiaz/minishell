/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/10 10:48:32 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_lstnew() Allocates (with malloc(3)) and returns a new node.             */
/* The member variable ’content’ is initialized with the value of the         */
/* parameter ’content’. The variable ’next’ is initialized to NULL.           */
/*                                                                            */
/* GETS                                                                       */
/*  *content: the content to create the node with                             */
/*                                                                            */
/* RETURNS                                                                    */
/*  The new node                                                              */
/*                                                                            */
/*                                                                            */
/* OPERATION                                                                  */
/*  Allocates memory enough for the structure                                 */
/*  When allocation is ok, set next to NULL and assign content pointer to     */
/*  the content field of the node                                             */
/*                                                                            */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node != NULL)
	{
		node->content = content;
		node->next = NULL;
	}
	return (node);
}
