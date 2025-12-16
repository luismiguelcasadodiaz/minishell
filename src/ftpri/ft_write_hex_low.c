/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:29:41 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/21 12:50:50 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
/* ************************************************************************** */
/* ft_write_hex_low() prints hexadecimal values of a number                   */
/*                                                                            */
/* GETS:                                                                      */
/* void *num:  the pointer which address to print                             */
/*                                                                            */
/* OPERATES:                                                                  */
/*                                                                            */
/* Calls a recursive generic function to print num in base 16 using the       */
/* digits 0..9 and letter a..f..                                              */
/*                                                                            */
/* RETURNS:                                                                   */
/* The result of calling the printing function.                               */
/* ************************************************************************** */
ssize_t	ft_write_hex_low(unsigned int num)
{
	ssize_t	digits;

	digits = 0;
	return (ft_write_uns_base(num, 16, "0123456789abcdef", &digits));
}
