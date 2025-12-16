/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/04/26 10:17:56 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_strjoin_int() creates new string the prefix and the integer suffix      */
/*                                                                            */
/* GETS                                                                       */
/*  s1: the prefix string.                                                    */
/*  num: the suffix integer.                                                  */
/*                                                                            */
/* RETURNS                                                                    */
/*  The new string resulting from s1 + itoa(num) concatenation or NULL if     */
/*  Rmalloc fails                                                             */
/*                                                                            */
/* OPERATION                                                                  */
/*  calculate prefix and suffix length and resulting string length.           */
/*  allocate memory for resulting string.                                     */
/*  copy the prefix to the resulting string                                   */
/*  concatenate the suffix to the resulting string.                           */

char	*ft_strjoin_int(char const *s1, int num)
{
	char	*itoa;
	char	*join;

	itoa = ft_itoa(num);
	join = ft_strjoin(s1, itoa);
	free(itoa);
	return (join);
}
