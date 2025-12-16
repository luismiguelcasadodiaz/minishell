/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:51:03 by maria-nm          #+#    #+#             */
/*   Updated: 2024/04/29 14:01:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int	check_dollar(char *word, int i)
{
	if (word[i] == '$' && (ft_isalpha(word[i + 1]) == 1 || word[i + 1] == '_'
			|| word[i + 1] == '?' || word[i + 1] == '\0'))
		return (1);
	return (0);
}
*/
int	check_dollar(char *word, int i)
{
	if (word[i] == '$')
	{
		if (word[i + 1] == '\0')
			return (2);
		if (ft_isalpha(word[i + 1]) == 1 || word[i + 1] == '_'
			|| word[i + 1] == '?' || word[i + 1] == '\0')
			return (1);
	}
	return (0);
}

int	check_tilde(char *w, int i)
{
	if (i == 0 && w[i] == '~' && (w[i + 1] == '/' || w[i + 1] == '\0'))
		return (1);
	return (0);
}

//checkea que exista dollar y devuelve la posicion donde lo ha encontrado.
//sino lo encuentra devuelve -1
int	check_expansor(t_lex *lexer)
{
	int	i;
	int	dollar;
	int	tilde;

	i = 0;
	tilde = 0;
	dollar = 0;
	if (lexer->token == STRING || lexer->token == STRING_TWO_Q)
	{
		if (lexer->token == STRING)
			tilde = check_tilde(lexer->word, i);
		dollar = check_dollar(lexer->word, i);
		while (dollar == 0 && lexer->word[i])
			dollar = check_dollar(lexer->word, i++);
		if (dollar == 1 || (dollar == 2 && lexer->next \
		&& (lexer->next->token == STRING_TWO_Q \
		|| lexer->next->token == STRING_ONE_Q)))
			return (i);
		else if (dollar == 2)
			return (-1);
		else if (tilde == 1)
			return (1);
		return (-1);
	}
	return (-1);
}

char	*make_new_word(t_lex *tmp, t_lex *tmp_next)
{
	size_t	len_new_word;
	char	*join;

	len_new_word = ft_strlen(tmp->word) + ft_strlen(tmp_next->word);
	join = (char *)malloc(len_new_word + 1);
	if (!join)
		return (NULL);
	ft_strlcpy(join, tmp->word, len_new_word + 1);
	ft_strlcat(join, tmp_next->word, len_new_word + 1);
	return (join);
}

int	check_cmd(char *command)
{
	int	i;

	i = 0;
	if (ft_isdigit(command[0]))
		return (1);
	while (command[i])
	{
		if (ft_isalnum(command[i]) == 0 && command[i] != '_')
			return (1);
		i++;
	}
	return (0);
}
