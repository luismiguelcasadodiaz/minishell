/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:55:02 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/15 13:55:21 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	len_word_special(char *str, int i, int j)
{
	if (ft_isspace(str[i]))
	{
		while (ft_isspace(str[i + j]))
			j++;
		return (j);
	}
	else if (ft_isreserved(str[i]))
		return (j);
	return (j);
}

static int	len_word_quote(char *str, int i, int j, t_lex *new)
{
	char	*word;

	word = NULL;
	j += look_next_quote(str, i + j);
	if (!ft_isquote(str[i + j]))
		word = ft_substr(str, i + 1, j);
	else
		word = ft_substr(str, i + 1, j - 1);
	if (!word)
		return (-1);
	new->word = word;
	return (j + 1);
}

int	make_word(char *str, int i, t_lex *new)
{
	char	*word;
	int		j;

	j = 0;
	word = NULL;
	if (ft_isspace(str[i]) || ft_isreserved(str[i]))
		return (len_word_special(str, i, j));
	else if (ft_isquote(str[i + j]))
		return (len_word_quote(str, i, j, new));
	else
	{
		while (str[i + j] && (!ft_isspace(str[i + j])
				&& !ft_isreserved(str[i + j]) && !ft_isquote(str[i + j])))
			j++;
		word = ft_substr(str, i, j);
		if (!word)
			return (-1);
		new->word = word;
		return (j);
	}
	return (j);
}
