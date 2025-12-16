/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:41:28 by maria-nm          #+#    #+#             */
/*   Updated: 2024/04/29 12:42:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_free_array(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	arr = NULL;
}

int	count_cmd(t_lex **lexer)
{
	int		i;
	t_lex	*tmp;

	if (lexer == NULL || *lexer == NULL)
		return (0);
	tmp = *lexer;
	i = 1;
	while (tmp)
	{
		if (tmp->token == PIPE)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	count_arg(t_lex *lexer)
{
	int	i;

	i = 0;
	while (lexer && lexer->token != PIPE)
	{
		if (lexer->next != NULL && (lexer->token == LESS
				|| lexer->token == LESS_LESS || lexer->token == GREAT
				|| lexer->token == GREAT_GREAT))
		{
			lexer = lexer->next;
			if (lexer->next == NULL || lexer->next->token == PIPE)
				return (i);
		}
		else
			i++;
		lexer = lexer->next;
	}
	return (i);
}
