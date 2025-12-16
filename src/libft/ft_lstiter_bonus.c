/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/12 16:35:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_lstiter() iterates the list and applies th funciotn 'f' to the content  */
/* of each node                                                               */
/*                                                                            */
/* GETS                                                                       */
/*  *lst : The address of a pointer to a node.                                */
/*  *del : The address of the function used to iterate on teh list            */
/*                                                                            */
/* RETURNS                                                                    */
/*  Nothing                                                                   */
/*                                                                            */
/* OPERATION                                                                  */
/*                                                                            */
/*   loops the list while there is a node to loop throu                       */
/*                                                                            */
/*  Apply 'f' function to actual node's content.                              */
/*  Advance to next node.                                                     */
/*                                                                            */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
