/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:42:12 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/05 15:56:47 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*obtain_var(char *str)
{
	char	*var;
	int		i;

	i = 0;
	str++;
	var = malloc(size_var(str) + 1);
	if (!var)
		return (NULL);
	if (str[i] == '?')
	{
		var[i] = str[i];
		var[++i] = '\0';
		return (var);
	}
	while (ft_isalnum(str[i]) == 1 || str[i] == '_')
	{
		var[i] = str[i];
		i++;
	}
	var[i] = '\0';
	return (var);
}
/*
int	ft_omit_var(char *var)
{
	int	i;

	i = 1;
	if (var[i] == '?')
		return (2);
	while (ft_isalnum(var[i]) || var[i] == '_')
		i++;
	return (i);
}
*/

int	ft_omit_var(char *var)
{
	int	i;

	i = 1;
	if (var[i] == '?')
		return (2);
	if (var[0] == '$')
	{
		while (var[i] && (ft_isalnum(var[i]) || var[i] == '_'))
			i++;
	}
	else if (var[0] == '~')
	{
		if (var[1] == '/' || var[1] == '\0')
			i = 1;
		else
			i = 0;
	}
	return (i);
}

//Obtain malloquea memoria para de $USER obtener USER
//arg_fin_env_var devuelve aun puntero a una direccion. 
//Value1 no hay uqe liberarlo.
char	*expand(char *str, char **env)
{
	char	*var;
	char	*value;
	char	*value1;

	var = obtain_var(str);
	if (var == NULL)
		return (NULL);
	value1 = arg_fin_env_var(env, var);
	if (!value1)
		return (free(var), NULL);
	value = arg_val_var(value1);
	if (!value)
		return (free(var), free(value1), NULL);
	free(var);
	return (value);
}

int	calc_len_value_exp(char *str, char **env, int *len)
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
	else if (str[0] == '~')
	{
		value = set_my_home(0, NULL);
		(*len) += ft_strlen(value);
	}
	else
	{
		value = expand(&str[i], env);
		(*len) += ft_strlen(value);
		i = ft_omit_var(&str[i]) - 1;
		free(value);
	}
	return (i);
}

int	calc_len_exp(t_lex *lexer, char **env)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (lexer->word[i] != '\0')
	{
		if (lexer->token == STRING || lexer->token == STRING_TWO_Q)
		{
			if ((lexer->word[i] == '$' || lexer->word[i] == '~'))
			{
				i += calc_len_value_exp(&(lexer->word[i]), env, &len);
			}
			else
				len++;
		}
		i++;
	}
	return (len);
}
