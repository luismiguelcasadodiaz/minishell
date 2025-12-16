/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:39:17 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/10 10:47:06 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>

/* ************************************************************************** */
/* analiza() calls the right function  with the right argument according to   */
/* the value of c.                                                            */
/*                                                                            */
/* GETS:                                                                      */
/* char c : the formater char that defines the funcion to print and the type  */
/*          to cast the argument to.                                          */
/*                                                                            */
/* OPERATES:                                                                  */
/* Only chars csdiupxX% select a function.                                    */
/* if %, a % has to be printed. 37 is the ascii value of %.                   */
/*                                                                            */
/*                                                                            */
/* RETURNS:                                                                   */
/* 0 when char is not in csdiupxX%.                                           */
/* The returned value from called function.                                   */
/*                                                                            */
/* ************************************************************************** */
static ssize_t	analiza(const char *fmt, size_t *i, va_list args)
{
	char	c;

	c = fmt[*i + 1];
	if (c == '%')
		return (ft_write_c(37));
	if (c == 'c')
		return (ft_write_c(va_arg(args, int)));
	if (c == 's')
		return (ft_write_str(va_arg(args, char *)));
	if (c == 'd')
		return (ft_write_dec(va_arg(args, int)));
	if (c == 'i')
		return (ft_write_int(va_arg(args, int)));
	if (c == 'u')
		return (ft_write_uns(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_write_ptr(va_arg(args, void *)));
	if (c == 'x')
		return (ft_write_hex_low(va_arg(args, int)));
	if (c == 'X')
		return (ft_write_hex_cap(va_arg(args, unsigned int)));
	return (0);
}

/* ************************************************************************** */
/* ft_printf() is a variadic functions that emulates printf() from stdio.h    */
/*                                                                            */
/* GETS                                                                       */
/*  *fmt is a pointe to a string with formaters that start by %               */
/*  ...  an undefined number of arguments                                     */
/*                                                                            */
/* RETURNS:                                                                   */
/*  The number of printed chars when sucess, -1 when fails                    */
/*                                                                            */
/* OPERATES:                                                                  */
/*  Initializes the treatement of the arguments starting after fmt.           */
/*                                                                            */
/*  Loops fmt printing, char by char, whatever different from %.              */
/*  When % shows up analizes next char                                        */
/*                                                                            */
/*  Ends the treatment of the arguments starting after fmt                    */
/* ************************************************************************** */
int	ft_printf(const char *fmt, ...)
{
	int		tot_chars;
	ssize_t	result;
	size_t	i;
	va_list	args;

	i = 0;
	tot_chars = 0;
	va_start(args, fmt);
	while (fmt[i] != '\0')
	{
		result = 0;
		if (fmt[i] != '%')
			result = ft_write_c(fmt[i]);
		else
		{
			result = analiza(fmt, &i, args);
			i++;
		}
		i++;
		if (result < 0)
			return (-1);
		tot_chars = tot_chars + result;
	}
	va_end(args);
	return (tot_chars);
}
