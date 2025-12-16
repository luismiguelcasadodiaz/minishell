/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:41:09 by maria-nm          #+#    #+#             */
/*   Updated: 2024/04/29 13:40:44 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_var(char *word, char *value, char *str, int len)
{
	if (value)
		ft_strlcat(str, value, len + 1);
	if (ft_strncmp(word, "$?", 2) == 0)
		free(value);
}

char	*create_value(char *word, int i, char **env)
{
	char	*value;

	if (word[i] == '~')
		value = set_my_home(0, NULL);
	else if (ft_strncmp(&word[i], "$?", 2) == 0)
		value = ft_itoa(exit_status(0, 0));
	else
		value = expand(&word[i], env);
	return (value);
}

void	change_token(t_lex *lexer, char *str)
{
	lexer->word = str;
	lexer->is_exp = 1;
}

int	expansor(t_lex **lexer, char **env)
{
	char	*str;
	t_lex	*c;

	c = *lexer;
	while (c)
	{
		if (c->token != GREAT && c->token != GREAT_GREAT \
		&& c->token != LESS && c->token != LESS_LESS && c->token != PIPE)
		{
			if (c->token != WHITE_SPACE && c->token != STRING_ONE_Q)
			{
				if (check_expansor(c) >= 0)
				{
					str = malloc(calc_len_exp(c, env) + 1);
					if (!str)
						return (1);
					ft_memset(str, '\0', calc_len_exp(c, env) + 1);
					make_expansion(c, env, str);
					change_token(c, str);
				}
			}
		}
		c = c->next;
	}
	return (0);
}
