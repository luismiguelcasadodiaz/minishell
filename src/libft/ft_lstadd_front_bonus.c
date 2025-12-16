/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/10 12:42:12 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_lstnew() adds the new node at the begining of the list.                 */
/* The member variable ’content’ is initialized with the value of the         */
/* parameter ’content’. The variable ’next’ is initialized to NULL.           */
/*                                                                            */
/* GETS                                                                       */
/*  **lst : The address of the pointer to the first link of the list.         */
/*  *new  : The address of the pointer to the node to be added to the list.   */
/* RETURNS                                                                    */
/*  Nothing.                                                                  */
/*                                                                            */
/*                                                                            */
/* OPERATION                                                                  */
/*  As the append is at the front, the appened node nest field has to point   */
/*  to the actual list starting adress.                                       */
/*  Then the actual list has to point to the new node.                        */
/*                                                                            */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
