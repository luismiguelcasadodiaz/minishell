/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:34:42 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/11 20:10:59 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_lstlast() returns the last node of the list.                            */
/*                                                                            */
/* GETS                                                                       */
/*  *lst : The begining of the list                                           */
/*                                                                            */
/* RETURNS                                                                    */
/*  The last node                                                             */
/*                                                                            */
/* OPERATION                                                                  */
/*                                                                            */
/*   When there is not list, returns same list                                */
/*                                                                            */
/*   If there is list                                                         */
/*       there is at least one node,                                          */
/*                                                                            */
/*       If the first node has no 'next', function does not enters into de    */
/*       while and returns actual node that is the first and the last one.    */
/*                                                                            */
/*       Inside the while, advances to the next node till there is not.       */
/*       when there is not next node, we are in the last node.                */
/*                                                                            */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}
