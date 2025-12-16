/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/09 16:58:13 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/* ft_putchar_fd() outputs the character 'c' to the given file descriptor fd. */
/*                                                                            */
/* GETS                                                                       */
/*  char c: the character to output.                                          */
/*  int fd: the file descriptor on which to write.                            */
/*                                                                            */
/* RETURNS                                                                    */
/*  None .                                                                    */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
