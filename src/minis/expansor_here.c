/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_here.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:30:04 by maria-nm          #+#    #+#             */
/*   Updated: 2024/06/27 18:30:32 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_expansion_here(char *line, char **env, int id[2], char *str)
{
	char	*value;

	value = create_value(line, id[0], env);
	if (value == NULL)
		value = "";
	id[1] = ft_strlcat(str, value, calc_len_exp_here(line, env) + 1);
	id[0] += ft_omit_var(&(line[id[0]])) - 1;
	if (value[0] != '\0')
		free(value);
}

static void	handle_normal_char_here(char *line, int index[2], char *str)
{
	str[index[1]] = line[index[0]];
	index[1]++;
}

/* index[0] = i, index[1] = j */
void	make_expansion_here(char *line, char **env, char *str)
{
	int		index[2];

	index[0] = 0;
	index[1] = 0;
	while (line[index[0]] != '\0')
	{
		if (check_dollar(line, index[0]) == 1 || \
		(check_dollar(line, index[0]) == 2))
			handle_expansion_here(line, env, index, str);
		else
			handle_normal_char_here(line, index, str);
		index[0]++;
	}
	str[index[1]] = '\0';
	free(line);
}

int	check_expansor_here(char *str)
{
	int	i;
	int	dollar;

	i = 0;
	dollar = check_dollar(str, i);
	while (dollar == 0 && str[i])
		dollar = check_dollar(str, i++);
	if (dollar == 1)
		return (i);
	else if (dollar == 2)
		return (-1);
	return (-1);
}

char	*expansor_here(char *line, char **env)
{
	char	*str;

	str = NULL;
	if (check_expansor_here(line) >= 0)
	{
		str = malloc(calc_len_exp_here(line, env) + 1);
		if (!str)
			return (str);
		ft_memset(str, '\0', calc_len_exp_here(line, env) + 1);
		make_expansion_here(line, env, str);
	}
	return (str);
}
