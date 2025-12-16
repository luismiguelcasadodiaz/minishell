/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/09 18:06:06 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/* write_nbr_fd() outputs the integer 'n' to the given file descriptor fd     */
/*                                                                            */
/* GETS                                                                       */
/*  char n: the integer to output.                                            */
/*  int fd: the file descriptor on which to write.                            */
/*                                                                            */
/* RETURNS                                                                    */
/*  None .                                                                    */
/*                                                                            */
/* OPERATES                                                                   */
/*  Calculates modulo for n divided by 10.                                    */
/*                                                                            */
/*  While the number has more than 1 digit, recursively reduces number's size */
/*  dividing it by 10.                                                        */
/*                                                                            */
/*  Behaves differently if number has 1 digit (0 <= n <= 9) or (-9 <= n <= 0) */
/*  accordingly to the sign. That happens to convert the digit into its ascii */
/*  equivalent                                                                */
/*                                                                            */
static void	write_nbr_fd(int n, int fd)
{
	int		num;
	char	c;

	num = n % 10;
	if (n > 0)
	{
		if (9 < n)
			write_nbr_fd(n / 10, fd);
		c = 48 + num;
		write(fd, &c, 1);
	}
	else
	{
		if (n < -9)
			write_nbr_fd(n / 10, fd);
		c = 48 - num;
		write(fd, &c, 1);
	}
}

/* ft_putnbr_fd() outputs the integer 'n' to the given file descriptor fd     */
/* followed by a newline.                                                     */
/*                                                                            */
/* GETS                                                                       */
/*  char n: the integer to output.                                            */
/*  int fd: the file descriptor on which to write.                            */
/*                                                                            */
/* OPERATES                                                                   */
/*  When integer n is negative output a minus sign                            */
/*  Write number n to the given descriptor                                    */
/*                                                                            */
/* RETURNS                                                                    */
/*  None .                                                                    */
void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, &"-", 1);
	write_nbr_fd(n, fd);
}
