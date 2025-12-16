/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/22 17:37:01 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* If c is an uppercase letter, ft_tolower() returns  its  lowercase          */
/* equivalent, if a lowercase representation exists in the current locale.    */
/*                                                                            */
/* Otherwise, it returns c.                                                   */
/*                                                                            */
/* If c is neither an unsigned char value nor EOF, the behavior of these      */
/* functions is undefined.                                                    */
/*                                                                            */
int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}
