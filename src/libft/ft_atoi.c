/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2024/06/06 20:13:09 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* my_isspace checks for white-space characters.                           */
/*                                                                         */
/*  In "C" and "POSIX" locales, these  are: space (' '), form-feed ('\f')  */
/*  newline ('\n'), carriage return ('\r'), horizontal tab ('\t'), and     */
/*  vertical tab ("\v")                                                    */
/*                                                                         */
/* RETURNS:                                                                */
/*  0 (false) if c is not an space                                         */
/*  1 (true)  if c belong to the "space" set                               */
/*                                                                         */
static int	my_isspace(int c)
{
	int	result;

	result = ((char)c == ' ');
	result = (result || ((char)c == '\f'));
	result = (result || ((char)c == '\n'));
	result = (result || ((char)c == '\r'));
	result = (result || ((char)c == '\t'));
	result = (result || ((char)c == '\v'));
	return (result);
}

/* ft_atoi() converts the INITIAL portion of the string pointed to by nptr to */
/* int.                                                                       */
/*                                                                            */
/* RETURNS                                                                    */
/* The converted value or 0 on error.                                         */
/*                                                                            */
/* OPERATION                                                                  */
/* 1.- skip leading spaces                                                    */
/* 2.-Sign defaults to positive (= 1).  when signs is negative substract 2    */
/*    from the sing. if sign exists, skip it (idx++).                         */
/* 3. evaluate all consecutive digits                                         */
/* 4. retunr total times sign (+/- 1)                                         */
/*                                                                            */
int	ft_atoi(const char *s)
{
	int		total;
	int		len;
	int		idx;
	short	sign;

	sign = 1;
	total = 0;
	len = ft_strlen(s);
	idx = 0;
	while ((my_isspace(s[idx])) && idx <= len)
		idx++;
	if ((s[idx] == '-') || (s[idx] == '+'))
		sign -= 2 * (s[idx++] == '-');
	while (ft_isdigit(s[idx]) && (idx <= len))
		total = total * 10 + (s[idx++] - '0');
	return (total * sign);
}
