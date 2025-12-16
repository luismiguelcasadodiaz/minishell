/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/12 10:44:38 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*                                                                            */
/* ft_substr() returns a substring from the string ’s’. The substring begins  */
/* at index ’start’ and is of maximum size ’len’.                             */
/*                                                                            */
/*                                                                            */
/* GETS                                                                       */
/*  str: The string from which to create the substring.                       */
/*  start: The start index of the substring in the string ’s’.                */
/*  len: The maximum length of the substring.                                 */
/*                                                                            */
/* RETURNS                                                                    */
/* The substring or NULL if the allocation fails.                             */
/*                                                                            */
/* OPERATION                                                                  */
/*  Calculate substring size:with starting point and 'len' chars to extract.  */
/*  CASE A: start is bigger than str_len. Returns EMPTY string (sub_len = 0)  */
/*     0123456789i01234567890                                                 */
/*  s [abcdefghij0]                                                           */
/*              ^                                                             */
/*    str_len = 10       ^                                                    */
/*                 start = 17                                                 */
/*                                                                            */
/*               -------------------------------                              */
/*                                                                            */
/*  CASE B: start is smaller than str_len.                                    */
/*     0123456789i01234567890                                                 */
/*  s [abcdefghij0]                                                           */
/*              ^                                                             */
/*    str_len = 10                                                            */
/*          ^                                                                 */
/*    start = 5                                                               */
/*                                                                            */
/*  When start + 'len' is bigger than string size then  substring size        */
/*  must be string size minus starting point. Otherwise substring of size len */
/*                                                                            */
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sub_len;
	size_t	str_len;

	if (!str)
		return (NULL);
	sub_len = 0;
	str_len = ft_strlen(str);
	if (start < str_len)
	{
		if ((start + len) > str_len)
			sub_len = str_len - start;
		else
			sub_len = len;
	}
	sub = (char *)malloc(sub_len + 1);
	if (sub == NULL)
		return (NULL);
	sub = (char *)ft_memcpy(sub, (str + start), sub_len);
	*(sub + sub_len) = '\0';
	return (sub);
}
