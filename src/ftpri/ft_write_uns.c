/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:29:41 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/09 16:12:33 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/* ************************************************************************** */
/* ft_write_uns() prints unsigned integer numbers                             */
/*                                                                            */
/* GETS:                                                                      */
/* unsigned int num:  the number to print                                     */
/*                                                                            */
/* OPERATES:                                                                  */
/* Calls a recursive generic function to print num in base 10 using the       */
/* digits 0..9                                                                */
/*                                                                            */
/* RETURNS:                                                                   */
/* The result of calling the printing function.                               */
/* ************************************************************************** */
ssize_t	ft_write_uns(unsigned int num)
{
	ssize_t	digits;

	digits = 0;
	return (ft_write_uns_base(num, 10, "0123456789", &digits));
}
