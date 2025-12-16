/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:42:06 by maria-nm          #+#    #+#             */
/*   Updated: 2024/04/29 13:48:12 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_isquote(int c)
{
	if (c == C_ONE_QUOTE || c == C_TWO_QUOTE)
		return (1);
	return (0);
}

int	ft_is_one_quote(int c)
{
	if (c == C_ONE_QUOTE)
		return (1);
	return (0);
}

int	ft_is_two_quote(int c)
{
	if (c == C_TWO_QUOTE)
		return (1);
	return (0);
}

int	ft_isreserved(int c)
{
	if (c == C_VERTICAL_BAR || c == C_LESS || c == C_GREAT)
		return (1);
	return (0);
}
