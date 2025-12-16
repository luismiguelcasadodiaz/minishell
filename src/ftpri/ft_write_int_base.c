/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/10 10:10:45 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ************************************************************************** */
/*  ft_win() is a generic function that prints NEGATIVE INTEGER values in     */
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
/*    When num to print is smaller or equals NEGATIVE base, calls again the   */
/*  to RECURSIVE function with an smaller num (num / base) made of the most   */
/*  significative digits. If something wrong, propagates it returning -1.     */
/*                                                                            */
/*    After printing correctly the most significative digits (num / base),    */
/*  print the less significative digit (num % base). As it is negative, sign  */
/*  changes (Kevin taught me) for indexing basechars[-pos].                   */
/*                                                                            */
/*  if everything was ok, adds one more digit to the count of printed digits  */
/*  and returns digits                                                        */
/*                                                                            */
/* ************************************************************************** */

static ssize_t	ft_win(int num, int base, char *basechars, ssize_t *digits)
{
	size_t	pos;
	ssize_t	result;

	if (num <= -base)
	{
		if (ft_win(num / base, base, basechars, digits) == -1)
			return (-1);
	}
	pos = num % base;
	result = write(FD, &basechars[-pos], 1);
	if (result == -1)
		return (-1);
	else if (result == 1)
	{
		*digits = *digits + 1;
		result = *digits;
	}
	return (result);
}

/* ************************************************************************** */
/*  ft_wip() is a generic function that prints POSITIVE INTEGER values in     */
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
static ssize_t	ft_wip(int num, int base, char *basechars, ssize_t *digits)
{
	size_t	pos;
	ssize_t	result;

	if (num >= base)
	{
		if (ft_wip(num / base, base, basechars, digits) == -1)
			return (-1);
	}
	pos = num % base;
	result = write(FD, &basechars[pos], 1);
	if (result == -1)
		return (-1);
	else if (result == 1)
	{
		*digits = *digits + 1;
		result = *digits;
	}
	return (result);
}

/* ************************************************************************** */
/*  ft_write_int_base() is a generic function that prints INTEGER value in    */
/*  different numeric bases using the right base digits.                      */
/*                                                                            */
/*  This funciton uses two recursive functions, one for positive numbers and  */
/*  one for negative numbers                                                  */
/*                                                                            */
/*  GETS                                                                      */
/*   int     num          Num to transform into chars if a base               */
/*   int     base         Base of num (10 decimal, 16,  octal                 */
/*   char    *basechars   set of char the base is made of                     */
/*   ssize_t *digits      passed by ref integer to return num of printed char */
/*                                                                            */
/*  RETURNS                                                                   */
/*    number of printed digits                                                */
/*                                                                            */
/*  OPERATES                                                                  */
/*    When num to print is positive call to RECURSIVE function for positives. */
/*                                                                            */
/*    When num to print is negative:                                          */
/*     1.- write negative sing. if problems retunr -1.                        */
/*     2.- Writting the sign increases printed digits in one unit.            */
/*     3.- call to recursive function for negatives.                          */
/*                                                                            */
/* ************************************************************************** */

ssize_t	ft_write_int_base(int num, int base, char *basechars, ssize_t *digits)
{
	ssize_t	result;

	if ((0 <= num) & (num <= INT_MAX))
		result = ft_wip(num, base, basechars, digits);
	else if (INT_MIN <= num)
	{
		if (write(FD, "-", 1) != 1)
			return (-1);
		*digits = *digits + 1;
		result = ft_win(num, base, basechars, digits);
	}
	else
		return (-1);
	if (0 < result)
		result = *digits;
	return (result);
}
