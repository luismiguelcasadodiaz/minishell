/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_uns_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/10 10:16:15 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/* ************************************************************************** */
/*  ft_wup() is a generic function that prints UNSIGNED LONG LONG values in   */
/*  different numeric bases using the right base digits.                      */
/*                                                                            */
/*  This RECURSIVE function MUST propagate two values:                        */
/*      a.- Error  (thru returned value)                                      */
/*      b.- Number of printed digits  (with pass by ref digits variable)      */
/*                                                                            */
/*  GETS                                                                      */
/*   int     num          Num to transform into chars if a base               */
/*   int     base         Base of num (10 decimal, 16,  octal                 */
/*   char    *basechars   set of char the base is made of                     */
/*   ssize_t *digits      passed by ref integer to return num of printed char */
/*                                                                            */
/*  RETURNS                                                                   */
/*    number of printed digits or error (-1)                                  */
/*                                                                            */
/*  OPERATES                                                                  */
/*    When num to print is bigger or equals base,  call again the             */
/*  to RECURSIVE function with an smaller num (num / base) made of the most   */
/*  significative digits. If something wrong, propagates it returning -1.     */
/*                                                                            */
/*    After printing correctly the most significative digits (num / base)i,   */
/*  prints the less significative digit (num % base). Uses pos for indexing   */
/*  basechars[-pos].                                                          */
/*                                                                            */
/*  if everything was ok, adds one more digit to the count of printed digits  */
/*  and returns digits                                                        */
/*                                                                            */
/* ************************************************************************** */
ssize_t	ft_wup(unsigned long long n,
						unsigned long long b,
						char *c,
						ssize_t *d)
{
	size_t	pos;
	ssize_t	result;

	if (n >= b)
	{
		if (ft_wup(n / b, b, c, d) == -1)
			return (-1);
	}
	pos = n % b;
	if (write(FD, &c[pos], 1) != 1)
		return (-1);
	else
	{
		*d = *d + 1;
		result = *d;
	}
	return (result);
}

/* ************************************************************************** */
/*  ft_write_uns_base() is a generic function that prints UNSIGNED values in  */
/*  different numeric bases using the right base digits.                      */
/*                                                                            */
/*  This funciton uses two recursive functions, one for positive numbers and  */
/*  one for negative numbers                                                  */
/*                                                                            */
/*  GETS                                                                      */
/*   unsigned long long n       Num to transform into chars if a base         */
/*   unsigned long long n       Base of num (10 decimal, 16,  octal           */
/*   char               *c      set of char the base is made of               */
/*   ssize_t            *d      passed by ref int. Returns num printed chars  */
/*                                                                            */
/*  RETURNS                                                                   */
/*    number of printed digits                                                */
/*                                                                            */
/*  OPERATES                                                                  */
/*    When num to print is positive call to RECURSIVE function for positives. */
/*                                                                            */
/*    When num to print is negative:                                          */
/*     DO NOTHING AS UNSIGNED ARE NOT NEGATIVES. Returns -1 cause it is an    */
/*     error try to print negative numbers with unsigned data type.           */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

ssize_t	ft_write_uns_base(unsigned long long n,
						unsigned long long b,
						char *c,
						ssize_t *d)
{
	ssize_t	result;

	if (n <= MY_ULL_MAX)
		result = ft_wup(n, b, c, d);
	else
		return (-1);
	if (0 < result)
		result = *d;
	return (result);
}
