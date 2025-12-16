/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/27 20:17:07 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* The ft_memcmp() function compares byte string s1 against byte string s2.   */
/* Both strings are assumed to be n bytes long.                               */
/*                                                                            */
/* RETURNS                                                                    */
/*                                                                            */
/* The ft_memcmp() function returns zero if the two strings are identical,    */
/* otherwise returns the difference between the first two differing bytes     */
/* (as unsigned char values, `\200' is greater than `\0',for example).     */
/*                                                                            */
/* Zero-length strings are always identical.                                  */
/*                                                                            */
/* This behavior is not required by C and portable code should only depend on */
/* the sign of the returned value.                                            */
/*                                                                            */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;
	size_t			idx;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	idx = 0;
	while (idx < n && uc_s1[idx] == uc_s2[idx])
		idx++;
	if (idx == n)
		return (0);
	else
		return (uc_s1[idx] - uc_s2[idx]);
}
