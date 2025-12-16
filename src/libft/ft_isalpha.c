/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:10:28 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/15 10:52:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isupper(int c)
{
	return ((65 <= c && c <= 90));
}

int	ft_islower(int c)
{
	return ((97 <= c && c <= 122));
}

/* The isalpha function tests for any character for which isupper or islower  */
/* is true.  The value of the argument must be representable as an unsigned   */
/* char or the value of EOF                                                   */

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
