/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:10:04 by maria-nm          #+#    #+#             */
/*   Updated: 2024/04/29 13:21:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//calcula las posiciones que tenemos que avanzar hasta encontrar el que buscamos
//devuelve -1 si no lo encuentra
int	ft_strlen_chr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	look_next_quote(char *str, int i)
{
	int	j;

	j = 1;
	while (str[i + j])
	{
		if (ft_isquote(str[i + j]) == 1)
		{
			if (str[i] == str[i + j])
				return (j);
		}
		j++;
	}
	return (j - 1);
}

int	ft_numlen(int n)
{
	int	qtt10;
	int	ext;
	int	len;

	ext = 0;
	len = 0;
	qtt10 = 1;
	while (qtt10 <= n && ext == 0)
	{
		if (qtt10 < 1000000000)
		{
			qtt10 *= 10;
			len++;
		}
		else
		{
			ext = 1;
			len++;
		}
	}
	if (n == 0)
		len = 1;
	return (len);
}

int	size_var(char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "?", 1) == 0)
		return (1);
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
		i++;
	return (i);
}

int	token_is_any_string(t_token token)
{
	int	result;

	result = (token == STRING);
	result = result || (token == STRING_ONE_Q);
	result = result || (token == STRING_TWO_Q);
	return (result);
}
