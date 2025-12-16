/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 10:43:28 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/07 19:24:27 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*.<*                                                                        .*/
/*.@file ft_msb.c                                                            .*/
/*.@brief ft_msb() Analyses argument's bits returning position for most      .*/
/*.       significant bit                                                    .*/
/*.                                                                          .*/
/*.@param[in] num: the num to look for the most significant bit in           .*/
/*.                                                                          .*/
/*.@returns a short holding the position of the bit most significative       .*/
/*.                                                                          .*/
/*.@details                                                                  .*/
/*.int	a=2048; 00000000000000000000100000000000  ft_msb(a) ==>12            .*/
/*.             21098765432109876543210987654321                             .*/
/*.                                                                          .*/
/*.int	b=1512; 00000000000000000000010111101000  ft_msb(a) ==>11            .*/
/*.             21098765432109876543210987654321                             .*/
/*.                                                                          .*/
/*.int	c=-512; 11111111111111111111111000000000  ft_msb(a) ==>31            .*/
/*.             21098765432109876543210987654321                             .*/
/*./author LMCD (Luis Miguel Casado Diaz)                                    .*/
/*.>*                                                                        .*/
/* ************************************************************************** */
short	ft_msb(int num)
{
	int		mask;
	int		size;
	int		msb;
	int		found;

	found = 0;
	size = sizeof(int) * 8;
	mask = 1u << (size - 2);
	msb = size;
	while (mask && !found)
	{
		found = (num & mask);
		mask = mask >> 1;
		msb--;
	}
	return (msb);
}
