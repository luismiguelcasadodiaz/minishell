/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/13 01:45:26 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_lstmap() iterates the list and applies function 'f' to the content of   */
/* each node. Creates a new list resulting of the sucessive applications of f */
/* function. The 'del' function is used to delete the content of a node if    */
/* needed.                                                                    */
/*                                                                            */
/* GETS                                                                       */
/*  *lst : The address of a pointer to a node.                                */
/*  *f   : The address of the function used to iterate on the list            */
/*  *del : The address of the function used to delete the content of a node.  */
/*                                                                            */
/* RETURNS                                                                    */
/*  the new list or NULL if allocation fails.                                 */
/*                                                                            */
/* OPERATION                                                                  */
/*                                                                            */
/*  If any of the three argument is null, returns null doing nothing          */
/*                                                                            */
/*  Inits new list to null.                                                   */
/*                                                                            */
/*   Loops the list while there is a node to loop throu                       */
/*                                                                            */
/*   Apply f to actual node's content, keeping the result in a buffer `buf.   */
/*                                                                            */
/*   Create a new node having by content 'buf'.                               */
/*                                                                            */
/*   When it does not succed, liberates 'buf' and clean from the new list     */
/*   previously added nodes. When ft_lstclear end, returns null, so ft_lstmap */
/*   at this point returns null.                                              */
/*                                                                            */
/*   When it suceed, add the new node to new_list last node.                  */
/*                                                                            */
/*   I prefer track last node to avoid looping thru the full list each time   */
/*   i call ft_lstadd_back                                                    */
/*                                                                            */
/*   Finally, advance the pointer in lst to the next node.                    */
/*                                                                            */
/*   At while end, retunrns the pointer to new list                           */
/*                                                                            */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_list_last;
	t_list	*new_node;
	void	*buf;

	new_list = NULL;
	while (lst)
	{
		buf = f(lst->content);
		new_node = ft_lstnew(buf);
		if (new_node == NULL)
		{
			del(buf);
			ft_lstclear(&new_list, del);
			return (new_list);
		}
		if (new_list == NULL)
			new_list = new_node;
		else
			new_list_last->next = new_node;
		new_list_last = new_node;
		lst = lst->next;
	}
	return (new_list);
}
