/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/27 20:26:45 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* The ft_strrchr() function returns a pointer to the last occurrence of the  */
/* character c in the string s.                                               */
/*                                                                            */
/* The function loops the string till string ends.                            */
/*   - when match happens it register the match in Last_found                 */
/*   - when string ends if nothing found (-1) checks if target was null-term  */
/*     If it was retunrs string end otherwise null                            */
/* RETURNS                                                                    */
/* ft_strrchr() function returnis a pointer to the matched character or NULL  */
/* if the character is not found.                                             */
/*                                                                            */
/* The terminating null byte is considered part of the string, so that if c   */
/* is specified as null, these functions return a pointer to the terminator   */
char	*ft_strrchr(const char *s, int c)
{
	size_t			idx;
	int				last_found;
	unsigned char	target;

	last_found = -1;
	idx = 0;
	target = (unsigned char)c;
	while (s[idx] != '\0')
	{
		if (s[idx] == target)
			last_found = idx;
		idx++;
	}
	if (last_found == -1 && target != '\0')
		return (NULL);
	if (last_found == -1 && target == '\0')
		return ((char *)(s + idx));
	return ((char *)(s + last_found));
}
