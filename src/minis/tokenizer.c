/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:36:15 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/14 13:04:52 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	identify_token(char *str, int i, t_lex *new)
{
	if (str[i] == C_VERTICAL_BAR)
		new->token = PIPE;
	else if (ft_isspace(str[i]) == 1)
		new->token = WHITE_SPACE;
	else if (ft_is_one_quote(str[i]) == 1)
		new->token = STRING_ONE_Q;
	else if (ft_is_two_quote(str[i]) == 1)
		new->token = STRING_TWO_Q;
	else if (str[i] == C_LESS && str[i + 1] != C_LESS)
		new->token = LESS;
	else if (str[i] == C_LESS && str[i + 1] == C_LESS)
		new->token = LESS_LESS;
	else if (str[i] == C_GREAT && str[i + 1] != C_GREAT)
		new->token = GREAT;
	else if (str[i] == C_GREAT && str[i + 1] == C_GREAT)
		new->token = GREAT_GREAT;
	else
		new->token = STRING;
}

static int	create_token(char *str, int i, t_lex *new)
{
	int	count;

	count = 0;
	identify_token(str, i, new);
	if (new->token == LESS_LESS || new->token == GREAT_GREAT)
		count = 2;
	else if (new->token == LESS || new->token == GREAT || new->token == PIPE)
		count = 1;
	else
		count = 0;
	return (count);
}

static int	init_lex_node(t_lex *new, char *str, int i)
{
	int	tmp;

	i += create_token(str, i, new);
	if (new->token != GREAT && new->token != GREAT_GREAT && new->token != LESS
		&& new->token != LESS_LESS && new->token != PIPE)
	{
		tmp = make_word(str, i, new);
		if (tmp == -1)
			return (-1);
		i += tmp;
	}
	return (i);
}

int	tokenizer(char *str, t_lex **lex)
{
	t_lex	*new;
	int		i;

	i = 0;
	while (str[i])
	{
		new = lex_lstnew();
		if (!new)
			return (1);
		lex_lstadd_back(lex, new);
		i = init_lex_node(new, str, i);
		if (i == -1)
			return (1);
	}
	return (0);
}
