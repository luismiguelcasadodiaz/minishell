/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <luicasad@student.42barcelona.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:50 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/21 09:23:54 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/* ************************************************************************** */
/* ft_write_str() prints decimal numbers                                      */
/*                                                                            */
/* GETS:                                                                      */
/* char *str: The string to printº                                            */
/*                                                                            */
/* OPERATES:                                                                  */
/* if the pointer is null , prints "(null)"                                   */
/*                                                                            */
/* Loops the string pirnting each characters. If problems exists loop         */
/*                                                                            */
/* During each loop iteration increasr char counter strlen.                   */
/*                                                                            */
/* RETURNS:                                                                   */
/* The length of the printed string when suceed, -1 when fails                */
/* ************************************************************************** */
ssize_t	ft_write_str(char *str)
{
	ssize_t	result;
	ssize_t	strlen;

	strlen = 0;
	if (!str)
		return (ft_write_str("(null)"));
	while (str[strlen] != '\0')
	{
		result = write(FD, &str[strlen], 1);
		if (result == -1)
			return (result);
		strlen++;
	}
	return (strlen);
}
