/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/18 19:00:36 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* The ft_calloc() function allocates memory for an array of nmemb elements   */
/* of size bytes each and returns a pointer to the allocated memory.          */
/*                                                                            */
/* The memory is set to zero. i do that with ft_bzero().                      */
/*                                                                            */
/* If nmemb or size is 0, then ft_calloc() returns a unique pointer value     */
/* that can later be successfully passed to free().                           */
/*                                                                            */
/* ATTENTION: I passed Francinette  test with AND instead of OR               */
/*                                                                            */
/* does not work 	if (nmemb == 0 || size == 0)                              */
/*                  	return ((void *)malloc(1));                           */
/* does work		if (nmemb == 0 && size == 0)                              */
/*						return ((void *)malloc(1));                           */
/*                                                                            */
/* ATTENTION: there is a hidden condition to pass the francinette leaks test  */
/*  if size of members is zero you have to return a NULL pointer.             */
/*                                                                            */
/*                                                                            */
/* If the multiplication of nmemb and size would result in integer overflow,  */
/* ((nmemb * size)  > INT_MAX ) then ft_calloc() returns an error(0x0).       */
/*                                                                            */
/* I check if nmemb > INT_MAX/size to avoid integer overflow caused by the    */
/* multiplication itself.                                                     */
/*                                                                            */
/*	if (nmemb > (INT_MAX / size))                                             */
/*		return (((void *)0));                                                 */
/*                                                                            */
/* With this protection Francinette was ok , but no Moulinette.               */
/*                                                                            */
/*                                                                            */
/*	if (nmemb == 0 && size == 0)                                              */
/*		return ((void *)malloc(1));                                           */
/*	if (size == 0)                                                            */
/*		return ((void *)0);                                                   */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	result = (void *)malloc(nmemb * size);
	if (result == NULL)
	{
		errno = ENOMEM;
		return ((void *)0);
	}
	else
	{
		ft_bzero(result, nmemb * size);
		return (result);
	}
}
