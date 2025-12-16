/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/16 10:27:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/* ft_putbits_fd() outputs the bits representing the int     'n' to the given */
/*                 file descriptor fd                                         */
/*                                                                            */
/* GETS                                                                       */
/*  int n: the integer to output.                                             */
/*  int fd: the file descriptor on which to write.                            */
/*                                                                            */
/* RETURNS                                                                    */
/*  None .                                                                    */
/*                                                                            */
/* OPERATES                                                                   */
/* creates a mask shifting to the left one 1 31 times.                        */
/*                                                                            */
/*                                                                            */
void	ft_putbits_fd(int n, int fd)
{
	int		mask;
	int		result;
	short	size;

	size = sizeof(int) * 8;
	mask = 1u << (size - 2);
	if (n < 0)
		write(fd, &"-", 1);
	else
		write(fd, &"+", 1);
	size--;
	while (size)
	{
		if ((size % 8) == 0)
			write(fd, &" ", 1);
		result = n & mask;
		if (result)
			write(fd, &"1", 1);
		else
			write(fd, &"0", 1);
		mask = mask / 2;
		size--;
	}
}
