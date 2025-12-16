/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/11 20:00:13 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_lstsize() counts the numbers of nodes in a list.                        */
/*                                                                            */
/* GETS                                                                       */
/*  *lst : The begining of the list                                           */
/* RETURNS                                                                    */
/*  The lenght of the list                                                    */
/*                                                                            */
/*                                                                            */
/* OPERATION                                                                  */
/*                                                                            */
/*   Inits the counter to zero.                                               */
/*                                                                            */
/*   When there is not list, returns 0 as list lenght                         */
/*                                                                            */
/*   If there is list                                                         */
/*       there is at least one node, so i set counter to one                  */
/*                                                                            */
/*       If the first node has no 'next', function does not enters into de    */
/*       while and returns one.                                               */
/*                                                                            */
/*       Inside the while, advances to the next node and increases counter.   */
/*       when actual node has not next node while exits.                      */
/*                                                                            */
int	ft_lstsize(t_list *lst)
{
	size_t	c;

	c = 0;
	if (lst)
	{
		c = 1;
		while (lst->next != NULL)
		{
			lst = lst->next;
			c++;
		}
	}
	return (c);
}
