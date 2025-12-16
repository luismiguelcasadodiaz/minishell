/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/10 00:53:24 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_striteri() Applies function ’f’ to each character of the string ’s’,    */
/* and passing its index as first argument. Each character is passeed by      */
/* address to be modified if necessary.                                       */
/*                                                                            */
/* GETS                                                                       */
/*  s: The string on which to iterate.                                        */
/*  s: The functio to apply to each character */
/*                                                                            */
/* RETURNS                                                                    */
/*  Nothing                                                                   */
/*                                                                            */
/* OPERATION                                                                  */
/*  Protect the function against null pointer is s.                           */
/*                                                                            */
/*      Apply function s to each char from s                                  */
/*                                                                            */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
