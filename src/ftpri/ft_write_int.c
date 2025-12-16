/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:29:41 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/09 16:11:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/* ************************************************************************** */
/* ft_write_int() prints integer numbers                                      */
/*                                                                            */
/* GETS:                                                                      */
/* int num:  the number to print                                              */
/*                                                                            */
/* OPERATES:                                                                  */
/* Calls a recursive generic function to print num in base 10 using the       */
/* digits 0..9                                                                */
/*                                                                            */
/* RETURNS:                                                                   */
/* The result of calling the printing function.                               */
/* ************************************************************************** */
ssize_t	ft_write_int(int num)
{
	ssize_t	digits;

	digits = 0;
	return (ft_write_int_base(num, 10, "0123456789", &digits));
}
