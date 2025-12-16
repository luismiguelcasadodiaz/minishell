/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/02 19:18:07 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* The  ft_strchr() function returns a pointer to the first occurrence of the */
/* character c in the string s.                                               */
/*                                                                            */
/* The function loops the string till there is a match or string ends.        */
/*   - when match happens it is returned.                                     */
/*   - when string ends if target was null returns string end otherwise NULL  */
/*                                                                            */
/* RETURNS                                                                    */
/* ft_strchr() function returnis a pointer to the matched character or NULL   */
/* if the character is not found.                                             */
/* The terminating null byte is considered part of the string, so that if c   */
/* is specified as null byte, returns a pointer to the terminator.            */
char	*ft_strchr(const char *s, int c)
{
	size_t			idx;
	unsigned char	target;

	idx = 0;
	target = (unsigned char)c;
	while (s[idx] != target && s[idx] != '\0')
		idx++;
	if (s[idx] == '\0' && target != '\0')
		return (NULL);
	return ((char *)(s + idx));
}
