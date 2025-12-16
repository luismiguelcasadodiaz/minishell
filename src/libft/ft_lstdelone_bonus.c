/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/13 01:47:06 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_lstdelone() frees the memory of the node's content using the function   */
/* del given as a parameter. frees the node itself but not the memory of next */
/*                                                                            */
/* GETS                                                                       */
/*   *lst : The node to free                                                  */
/*   *del : The address of the function used to delete the content            */
/*                                                                            */
/* RETURNS                                                                    */
/*  NOthing                                                                   */
/*                                                                            */
/* OPERATION                                                                  */
/*                                                                            */
/*   Content is a void* inside the node, so we call del function passing      */
/*   lst->content  as argument.                                               */
/*                                                                            */
/*   The function release actual node                                         */
/*                                                                            */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
