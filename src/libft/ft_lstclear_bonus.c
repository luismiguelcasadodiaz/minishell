/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/12 16:22:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_lstclear() deletes and frees the given node and every successor of that */
/* node, using the funciton 'del' and free. Finally the pointer to the list   */
/* must be set to null.                                                       */
/*                                                                            */
/* GETS                                                                       */
/*  *lst : The address of a pointer to a node.                                */
/*  *del : The address of the function used to delete the content of the node */
/*                                                                            */
/* RETURNS                                                                    */
/*  Nothing                                                                   */
/*                                                                            */
/* OPERATION                                                                  */
/*                                                                            */
/*   loops the list while there is a node to loop throu                       */
/*                                                                            */
/*   Inside the while 'actual' keeps the address of node.                     */
/*   'lst' moves to next node of actual to check again the while condition.   */
/*   At list end, lst will get NULL, as required in the specification.        */
/*                                                                            */
/*   calls del function to remove actual's content.                           */
/*   release actual memory                                                    */
/*                                                                            */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*actual;

	while (*lst)
	{
		actual = *lst;
		*lst = actual->next;
		del(actual->content);
		free(actual);
	}
}
