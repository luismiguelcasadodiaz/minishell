/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/14 19:31:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_isascii() function tests for an ASCII character, which is any       */
/* character between 0 and decimal 127 inclusive                             */
int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
