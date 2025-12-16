/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2024/06/06 20:17:04 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_is_punc is a helper funciton to verificate the differente character     */
/* ranges.                                                                    */
/*   040 sp        041 ``!''     042 ``"''     043 ``#''     044 ``$''        */
/*   045 ``%''     046 ``&''     047 ``'''     050 ``(''     051 ``)''        */
/*   052 ``*''     053 ``+''     054 ``,''     055 ``-''     056 ``.''        */
/*   057 ``/''                                                                */
/*                                                                            */
/*   072 ``:''     073 ``;''     074 ``<''     075 ``=''     076 ``>''        */
/*   077 ``?''     100 ``@''                                                  */
/*                                                                            */
/*   133 ``[''     134 ``\''     135 ``]''     136 ``^''     137 ``_''      */
/*   140 ```''                                                                */
/*                                                                            */
/*   173 ``{''     174 ``|''     175 ``}''     176 ``~''                      */
/*                                                                            */

static int	ft_is_punc(int c)
{
	int	is_punc;

	is_punc = (32 <= c && c <= 47);
	is_punc = (is_punc || (58 <= c && c <= 64));
	is_punc = (is_punc || (91 <= c && c <= 96));
	is_punc = (is_punc || (123 <= c && c <= 126));
	return (is_punc);
}

/* The isprint() function tests for any printing character, including space   */
/* (` ').  The value of the argument must be representable as an unsigned     */
/* char or the value of EOF.                                                  */
int	ft_isprint(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c) || ft_is_punc(c));
}
