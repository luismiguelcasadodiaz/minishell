/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/11 01:28:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
/* allocate_space_for() allocates memory to show int n as a string            */
/*                                                                            */
/* GETS                                                                       */
/*  n   : is the integer to convert to string                                 */
/*  *pos: is string length for required to show int n as a string             */
/*                                                                            */
/* RETURNS                                                                    */
/*  Nothing, but worth to know that pos is a variable passed by reference     */
/*  That communicates to calling function the string's length of the required */
/*  string to show int n as an string.                                        */
/*                                                                            */
/* OPERATES                                                                   */
/*  When n is negative (n <  0) at least requires 2-figure string.            */
/*  When n is positive (0 <= n) at least requires 1-figure string.            */
/*                                                                            */
/*  n /= 10 removes less significative digit from n.                          */
/*                                                                            */
/*  While there are digits it counts and removes digits.                      */
/*                                                                            */
/*  Once number of digits in known, allocates memory for the figures plus the */
/*  string null-terminator.                                                   */
/*                                                                            */
/*  if there is memory availabel initializes the string with white spaces and */
/*  returns the new creates string.                                           */
/*                                                                            */
char	*allocate_space_for(int n, size_t *pos)
{
	char	*str;
	size_t	figures;

	if (n < 0)
		figures = 2;
	else
		figures = 1;
	n /= 10;
	while (n)
	{
		figures = figures + 1;
		n /= 10;
	}
	str = (char *)malloc((figures + 1) * sizeof(char));
	if (str != NULL)
	{
		str[figures] = '\0';
		*pos = figures - 1;
		while (figures)
			str[--figures] = ' ';
		str[figures] = ' ';
	}
	return (str);
}

/* ************************************************************************** */
/* aux_itoa()is a recursive function that extract digits from an integer and  */
/* inserts them in the right position of a string with the right spaces to    */
/* hold all figures comming from the integer.                                 */
/*                                                                            */
/* GETS                                                                       */
/*  n     : The integer to extract digits from.                               */
/*  **str : Address of the pointer to  the string to append to digit          */
/*  *pos  : The lenght of the string that holds the integer.                  */
/*                                                                            */
/* RETURNS                                                                    */
/*  Nothing, but worths to be aware that thru **str there is communication    */
/*  with the calling function.                                                */
/*                                                                            */
/* OPERATES                                                                   */
/*  Treates diferently accordingly to integer's sign.                         */
/*                                                                            */
/*  When the integer has more than one digit, reduce integer size dividing    */
/*  by 10.                                                                    */
/*                                                                            */
/*  When the integer has one digit (n <= 9), calculate his ascii char.        */
/*                                                                            */
/*                         num = 48 + n % 10                                  */
/*                                                                            */
/*  When n is INT_MIN (-2147 483 648) the required sign change happens in     */
/*  the result of the modulo operation. I wait to change the sign when the    */
/*  integer is small.                                                         */
/*                                                                            */
/*             ----------------------------------------                       */
/*                         num = 48 + (-n % 10)                               */
/*  That does not work with INT_MIN                                           */
/*                                                                            */
/*  Recursively the function extract the less significant figure from the int */
/*  in such a way the figure is inserted in the string from the right to the  */
/*  left, from n towards zero index. Then in each recursive call we have to   */
/*  decrease the position where to insert the figure (pos -1)                 */
/*                                                                            */

static void	aux_itoa(int n, char **str, size_t pos)
{
	char	num;

	if (0 < n)
	{
		if (9 < n)
			aux_itoa(n / 10, str, pos - 1);
		num = 48 + n % 10;
	}
	else
	{
		if (n < -9)
			aux_itoa(n / 10, str, pos - 1);
		num = n % 10;
		num = 48 - num;
	}
	str[0][pos] = num;
}

/* ft_itoa() allocates (with malloc(3)) and returns a strings representing    */
/* the integer received as an argument.                                       */
/* Negative numbers must be handlepointer                                .    */
/*                                                                            */
/* GETS                                                                       */
/*  n: the integer to convert                                                 */
/*                                                                            */
/* RETURNS                                                                    */
/*   The string representing the intege                                       */
/*   NULL if memory allocation fails.                                         */
/*                                                                            */
/* OPERATION                                                                  */
/*  Starts creating an empty (filled wiht spaces) string of enought lenght    */
/*  to hold all figures in the integer.                                       */
/*                                                                            */
/*  When n = 0 add a '0' to the empty string n the position 0 of a string of  */
/*  length 1.                                 */
/*                                                                            */
/*  When n is positive convert the integer into string                        */
/*                                                                            */
/*  When n is negative convert the integer into string and add '-' to head    */
/*                                                                            */
/* PROBLEMS I GOT                                                             */
/* I complicated my life with an approach to allocate memory for the string   */
/* representing the integer gradually as new digits are required. You can see */
/* it in this repository in ft_itoa_one_by_one.c                              */
/*                                                                            */
/* As i did not manage to pass the fsoares test ft_itoa(0), then i figured    */
/* out this other approach i can call ft_itoa_all_at_once.c                   */
/*                                                                            */
/* I learn to deal with a pointer passed by reference to a function           */

char	*ft_itoa(int n)
{
	char	*str;
	size_t	pos;

	str = allocate_space_for(n, &pos);
	if (str)
	{
		if (n == 0)
			str[0] = '0';
		if (n > 0)
		{
			aux_itoa(n, &str, pos);
		}
		if (n < 0)
		{
			aux_itoa(n, &str, pos);
			str[0] = '-';
		}
	}
	return (str);
}
