/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2024/05/02 11:25:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* If c is an lowercase letter, ft_toupper() returns  its  uppercase          */
/* equivalent, if a lowercase representation exists in the current locale.    */
/*                                                                            */
/* Otherwise, it returns c.                                                   */
/*                                                                            */
/* If c is neither an unsigned char value nor EOF, the behavior of these      */
/* functions is undefined.                                                    */
/*                                                                            */
int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}
