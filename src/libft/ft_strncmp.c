/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/09 08:59:59 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* The ft_strncmp() function compares the first (at most) n bytes of the two  */
/* strings s1 and s2.                                                         */
/* The comparison is done using unsigned characters.                          */
/*                                                                            */
/* RETURNS                                                                    */
/*                                                                            */
/* An integer indicating the result of the comparison, as follows:            */
/*   •  0, if the s1 and s2 are equal;                                        */
/*   •  a negative value if s1 is less than s2;                               */
/*   •  a positive value if s1 is greater than s2.                            */
/*                                                                            */
/* OPERATION                                                                  */
/* While there are chars in the strings and idx smaller than n the funcition  */
/* checks if chars in same position are equal.                                */
/*                                                                            */
/* if the while pushed the idx till n means that the strings have the first   */
/* n char equal so the fucntion returns 0.                                    */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;
	size_t			i;

	if (n)
	{
		ucs1 = (unsigned char *) s1;
		ucs2 = (unsigned char *) s2;
		i = 0;
		while (i < n && s1[i] != '\0' && s2[i] != '\0' && ucs1[i] == ucs2[i])
			i++;
		if (i >= n)
			return (0);
		else
			return (ucs1[i] - ucs2[i]);
	}
	return (0);
}
