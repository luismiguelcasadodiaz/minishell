/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/10 00:32:23 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_strmapi() Applies the function ’f’ to each character of the string ’s’, */
/* and passing its index as first argument to create a new string (with       */
/* malloc(3)) resulting from successive applications of ’f’                   */
/*                                                                            */
/* GETS                                                                       */
/*  s: The string on which to iterate.                                        */
/*  s: The functio to apply to each character.                                */
/*                                                                            */
/* RETURNS                                                                    */
/*  The new string created from the succerrive applications of 'f'            */
/*  NULL if the memory allocation fails.                                      */
/*                                                                            */
/* OPERATION                                                                  */
/*  Protect the function against null pointer is s.                           */
/*                                                                            */
/*  Allocate memory for the resulting string.                                 */
/*                                                                            */
/*  If memory allocation is ok loop string s                                  */
/*      Apply function s to each cahr from s saving result in new_string      */
/*                                                                            */
/*  Null-terminate new_s                                                      */
/*                                                                            */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			s_len;
	unsigned int	i;
	char			*new_s;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	new_s = (char *)malloc((s_len + 1) * sizeof(char));
	if (new_s)
	{
		i = 0;
		while (i < s_len)
		{
			new_s[i] = f(i, s[i]);
			i++;
		}
		new_s[i] = '\0';
	}
	return (new_s);
}
