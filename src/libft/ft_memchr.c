/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/20 13:17:05 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* The ft_memchr() function locates the first occurrence of c (converted to   */
/* an unsigned char) in string s.                                             */
/*                                                                            */
/* RETURNS                                                                    */
/*                                                                            */
/* returns a pointer to the byte located, or NULL if no such byte exists      */
/* within n bytes                                                             */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
void	*ft_memchr(const void *s, int c, size_t n)
{
	void			*result;
	size_t			bytes;
	unsigned char	*uc_s;
	short			found;
	unsigned char	searched;

	result = NULL;
	if (n)
	{
		uc_s = (unsigned char *)s;
		searched = (unsigned char)c;
		bytes = 0;
		found = 0;
		while (bytes < n && !found)
		{
			if (uc_s[bytes] == searched)
				found = 1;
			else
				bytes++;
		}
		if (found)
			result = &uc_s[bytes];
	}
	return (result);
}
