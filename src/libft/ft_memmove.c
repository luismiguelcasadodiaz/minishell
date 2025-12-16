/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/10 09:13:58 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* The ft_memmove() function copies len bytes from string src to string dst.  */
/* The two strings may overlap; the copy is always done in a non-destructive  */
/* manner.                                                                    */
/*                                                                            */
/* GETS                                                                       */
/* dst : starting memory address to move bytes to                             */
/* src : starting memory address to move bytes from                           */
/* len : numbers of bytes to move                                             */
/*                                                                            */
/* RETURN VALUES                                                              */
/* The function returns the original value of dst (the pointer)               */
/*                                                                            */
/* OPERATION                                                                  */
/*  programmer mindset ==> forget strings exists. think in bytes              */
/*                                                                            */
/*  lower memory                                                higher memory */
/* 0........................................................................n */
/*  case  A:  dst < src                                                       */
/*  case A1:  dst + len < src         NO OVERLAPP                             */
/*      dst   ............                                                    */
/*                                          src ...............               */
/*      copies len bytes from src low to high mem     .                       */
/*                                                                            */
/*  case A2:  dst + len >= src       OVERLAPS                                 */
/*      dst   ............                                                    */
/*                 src ...............                                        */
/*      copies len bytes from src low to high mem. DESTROYS SRC init          */
/*                                                                            */
/*                       ------------------------------                       */
/*                                                                            */
/*  case  B:  dst > src                                                       */
/*  case B1:  src + len < dst                                                 */
/*      src   ............           NO OVERLAP                               */
/*                                          dst ...............               */
/*      copies len bytes from src high to low mem                             */
/*                                                                            */
/*  case B2:  src + len > dst                                                 */
/*      src   ............                                                    */
/*                 dst ...............                                        */
/*      copies len bytes from src high to low mem. DESTROYS SRC end           */
/*                                                                            */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				idx;

	if (dst == NULL && src == NULL)
		return (dst);
	if (dst < src)
	{
		idx = 0;
		while (idx < len)
		{
			((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
			idx++;
		}
	}
	if (src <= dst)
	{
		while (len)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}
