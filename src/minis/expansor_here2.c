/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_here2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:34:16 by maria-nm          #+#    #+#             */
/*   Updated: 2024/06/28 16:34:39 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	calc_len_value_exp_here(char *str, char **env, int *len)
{
	int		i;
	char	*value;

	i = 0;
	value = NULL;
	if (ft_strncmp(str, "$?", 2) == 0)
	{
		(*len) += ft_numlen(exit_status(0, 0));
		i += 1;
	}
	else if (str[0] == '$' && !(ft_isalnum(str[1]) || str[1] == '_'))
		(*len) += 1;
	else
	{
		value = expand(&str[i], env);
		(*len) += ft_strlen(value);
		i = ft_omit_var(&str[i]) - 1;
		free(value);
	}
	return (i);
}

int	calc_len_exp_here(char *str, char **env)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			i += calc_len_value_exp_here(&(str[i]), env, &len);
		}
		else
			len++;
		i++;
	}
	return (len);
}
