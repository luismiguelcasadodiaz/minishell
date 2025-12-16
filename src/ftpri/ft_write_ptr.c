/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:29:41 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/10 09:08:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/* ************************************************************************** */
/* ft_write_ptr() prints hexadecimal address of a pointer                     */
/*                                                                            */
/* GETS:                                                                      */
/* void *num:  the pointer which address to print                             */
/*                                                                            */
/* OPERATES:                                                                  */
/* Casts the pointer to unsigned long long.                                   */
/*                                                                            */
/* Prints "0x" prefix. If result not 2 characters printed, then returns -1    */
/*                                                                            */
/* Calls a recursive generic function to print num in base 16 using the       */
/* digits 0..9 and letter a..f.. Informs this function that 2 characters      */
/* already have been printed.                                                 */
/*                                                                            */
/* RETURNS:                                                                   */
/* The result of calling the printing function.                               */
/* ************************************************************************** */
ssize_t	ft_write_ptr(void *num)
{
	ssize_t				digits;
	unsigned long long	my_num;

	my_num = (unsigned long long)num;
	if (my_num == 0)
	{
		if (ft_write_str("(nil)") != 5)
			return (-1);
		else
			return (5);
	}
	if (ft_write_str("0x") != 2)
		return (-1);
	digits = 2;
	return (ft_write_uns_base(my_num, 16, "0123456789abcdef", &digits));
}
