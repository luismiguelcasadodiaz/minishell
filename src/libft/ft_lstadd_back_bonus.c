/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/11 22:31:56 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_lstadd_back() adds a note to the end of the list                        */
/*                                                                            */
/* GETS                                                                       */
/*  **lst : The begining of the list                                          */
/*   *new : the node to concatenate at list end                               */
/*                                                                            */
/* RETURNS                                                                    */
/*  NOthing                                                                   */
/*                                                                            */
/* OPERATION                                                                  */
/*                                                                            */
/*   When there is not list, returns the node we want to add as the first one */
/*                                                                            */
/*   If there is list                                                         */
/*       Find the last node from the list                                     */
/*                                                                            */
/*       link last node to new one.                                           */
/*                                                                            */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}
