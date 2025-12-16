/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/27 20:24:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* The strlen() function computes the length of the string s                  */
/* a while loop counts chars till it finds null-terminator                    */
/* RETURNS the number of characters preceding the terminating NUL character   */

// ==== this version that checks null values does not pass paco =============

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	if (s != NULL)
	{
		idx = -1;
		while (s[++idx] != '\0')
			;
		return (idx);
	}
	else
		return (0);
}

/* 6.72seg when executed 100 000 000 times if compiled without -O flag */
/* 1.97seg when executed 100 000 000 times if compiled with -O1 flag   */
/* 1.92seg when executed 100 000 000 times if compiled with -O3 flag   */
/*
size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}
*/
/* 7.21seg when executed 100 000 000 times if compiled without -O flag */
/* 1.97seg when executed 100 000 000 times if compiled with -O1 flag   */
/* 1.92seg when executed 100 000 000 times if compiled with -O3 flag   */
/*
size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = -1;
	while (s[++idx])
		;
	return (idx);
}
*/
/*  9,85seg when executed 100 000 000 times if compiled without -O flag */
/* 1.97seg when executed 100 000 000 times if compiled with -O1 flag   */
/* 1.92seg when executed 100 000 000 times if compiled with -O3 flag   */
/*
size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (*(s + idx))
		idx++;
	return (idx);
}
*/
