/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/19 14:07:55 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* The bzero() function writes n zeroed bytes to the string s.                */
/*  If n is  zero, bzero() does nothing.*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	fill;
	size_t			idx;

	fill = '\0';
	idx = 0;
	if (n)
	{
		while (n--)
			((unsigned char *)s)[idx++] = fill;
	}
	return ;
}
