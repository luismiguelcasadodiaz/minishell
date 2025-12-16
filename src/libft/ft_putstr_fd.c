/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/09 18:05:43 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/* ft_putstr_fd() outputs the string 's' to the given file descriptor fd. */
/*                                                                            */
/* GETS                                                                       */
/*  char c: the string to output.                                          */
/*  int fd: the file descriptor on which to write.                            */
/*                                                                            */
/* RETURNS                                                                    */
/*  None .                                                                    */

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
}
