/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/27 16:48:02 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/* this function helps me to pass paco test as he wants a gesfault when big   */
/* is null                                                                    */
static void	force_segfault(void)
{
	int	*p;

	p = NULL;
	*p = 1;
}
/* max_idx() is a helper function, that calculates the last position to start */
/* a match verification.                                                      */
/*                                                                            */
/* GETS                                                                       */
/*  big_len : length of string to search in                                   */
/*  lit_len : leggth of stinrg to look for                                    */
/*  len     : chunk of big 0.. len where match has to happend                 */
/*                                                                            */
/* RETURNS                                                                    */
/*  Last posiiton of big where to try a match                                 */
/*                                                                            */
/* OPERATION                                                                  */
/* We have to limit the match inside the first len chars of big.              */
/*                                                                            */
/* Does lit fits in len?       lit_len <= len                                 */
/*                                                                            */
/* if it DOES NOT, the match is imposible. len will exhaust before finish the */
/* match verification. Return big_len + 1 ==> null-terminator character       */
/*  Nothing will happend.                                                     */
/* if it DOES. the match only will start before len - lit-len.                */
/*                                                                            */
/*                      lit_len                                               */
/*                      ---^----                                              */
/*                      01234567                                              */
/*                     |LLLLLLLL|                                             */
/* big ==> "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"   */
/*          01234567890123456789012345678901234567890123456789012345678901    */
/*                    1         2         3         4         5         6     */
/*                      ^      ^                                              */
/*                idx_max      len                                            */
/* big_len = 62                                                               */
/* lit_len =  8                                                               */
/* len     = 20                                                               */
/* idx_max = len - lit_len  = 20 - 8  = 12                                    */

static size_t	max_idx(size_t big_len, size_t lit_len, size_t len)
{
	if (lit_len < big_len)
		return (len - lit_len);
	else
		return (big_len + 1);
}

static char	*my_find(const char	*b, const char *l, size_t ll, size_t len)
{
	size_t	i_big;
	size_t	i_big_max;
	short	found;

	i_big_max = max_idx(ft_strlen(b), ll, len);
	i_big = 0;
	found = 0;
	while (!found && (i_big <= i_big_max))
	{
		if (ft_memcmp((b + i_big), l, ll) == 0)
			found = 1;
		i_big++;
	}
	if (found)
		return ((char *)(b + (--i_big)));
	else
		return ((void *)0);
}

/* The ft_strnstr() function locates the first occurrence of the null-term    */
/* string little in the string big, where not more than len characters are	  */
/* searched. Characters after a null-terminator character are not  searched.  */
/*                                                                            */
/* GETS                                                                       */
/*  big: a null-terminated string where to find the 'lit'  substr.            */
/*  lit: a null-terminated string to find inside 'big'.                       */
/*  len: the max num of chars of 'big' to start the search of 'lit'           */
/*                                                                            */
/* RETURNS                                                                    */
/*  'big' when 'lit'  equals ""                                               */
/*  NULL  when 'lit' does not occur in 'big'.                                 */
/*  a pointer to the first char of 'big' where starts the first 'lit'         */
/*                                                                            */
/* OPERATION                                                                  */
/*  if 'lit' is empty returns'big'                                            */
char	*ft_strnstr(const char	*big, const char *lit, size_t len)
{
	char	*result;
	size_t	lit_len;

	if (big == NULL)
		force_segfault();
	if ((lit[0] != '\0'))
	{
		lit_len = ft_strlen(lit);
		if (len >= lit_len)
			result = my_find(big, lit, lit_len, len);
		else
			result = NULL;
	}
	else
		result = (char *)(big);
	return (result);
}
