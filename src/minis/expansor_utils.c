/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:48:16 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/31 12:48:42 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_control(t_lex *lexer, int i)
{
	if ((check_dollar(lexer->word, i) == 1 || check_tilde(lexer->word, i)) \
		|| (check_dollar(lexer->word, i) == 2 \
		&& lexer->next && (lexer->next->token == STRING_ONE_Q \
		|| lexer->next->token == STRING_TWO_Q)))
		return (1);
	return (0);
}

static void	handle_expansion(t_lex *lexer, char **env, int index[2], char *str)
{
	char	*value;
	int		is_virgu;

	is_virgu = (lexer->word[0] == '~');
	value = create_value(lexer->word, index[0], env);
	if (value == NULL)
		value = "";
	index[1] = ft_strlcat(str, value, calc_len_exp(lexer, env) + 1);
	index[0] += ft_omit_var(&(lexer->word[index[0]])) - 1;
	if (value[0] != '\0' && !is_virgu)
		free(value);
}

static void	handle_normal_char(t_lex *lexer, int index[2], char *str)
{
	str[index[1]] = lexer->word[index[0]];
	index[1]++;
}

/* index[0] = i, index[1] = j */
void	make_expansion(t_lex *lexer, char **env, char *str)
{
	int		index[2];

	index[0] = 0;
	index[1] = 0;
	while (lexer->word[index[0]] != '\0')
	{
		if (check_control(lexer, index[0]) == 1)
			handle_expansion(lexer, env, index, str);
		else
			handle_normal_char(lexer, index, str);
		index[0]++;
	}
	str[index[1]] = '\0';
	free(lexer->word);
}
/*
void	make_expansion(t_lex *lexer, char **env, char *str)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	j = 0;
	while (lexer->word[i] != '\0')
	{
		if (check_control(lexer, i) == 1)
		{
			value = create_value(lexer->word, i, env);
			if (value == NULL)
				value = "";
			j = ft_strlcat(str, value, calc_len_exp(lexer, env) + 1);
			i += ft_omit_var(&(lexer->word[i])) - 1;
			if(value[0] != '\0')
				free(value);
		}
		else
		{
			str[j] = lexer->word[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	free(lexer->word);
}
*/
/*
void	make_expansion(t_lex *lexer, char **env, char *str)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	j = 0;
	while (lexer->word[i] != '\0')
	{
		if ((check_dollar(lexer->word, i) || check_tilde(lexer->word, i)))
		{
			value = create_value(lexer->word, i, env);
			if (value == NULL)
				value = "";
			j = ft_strlcat(str, value, calc_len_exp(lexer, env) + 1);
			i += ft_omit_var(&(lexer->word[i])) - 1;
		}
		else
		{
			str[j] = lexer->word[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}
*/
