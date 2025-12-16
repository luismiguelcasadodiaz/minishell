/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:10:31 by maria-nm          #+#    #+#             */
/*   Updated: 2025/12/16 20:34:47 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_make_flg(t_lex *current)
{
	if (current->next != NULL && (current->token == LESS
			|| current->token == LESS_LESS || current->token == GREAT
			|| current->token == GREAT_GREAT))
		return (1);
	return (0);
}

static t_lex	*update_parser_links(t_lex *current)
{
	current = current->next;
	return (current);
}

t_lex	*make_flg(t_ecmd *cmd, t_lex *node, int arg, t_lex **list)
{
	int		j;
	t_lex	*current;

	j = 0;
	current = node;
	while (current && current->token != PIPE && j < arg)
	{
		if (check_make_flg(current) == 1)
		{
			current = current->next;
			if (current->next == NULL || current->next->token == PIPE)
				return (update_parser_links(current));
			current = current->next;
		}
		else
		{
			cmd->flg[j] = current->word;
			j++;
			current = remove_node(current, list);
			if (current == NULL)
				return (NULL);
		}
	}
	return (current);
}

static int	create_flags(t_exec *inter, t_lex **list, int i, t_lex **lexer)
{
	int		arg;

	arg = count_arg(*list);
	inter->cmds[i]->flg = (char **)malloc((arg + 1) * sizeof (char *));
	if (!inter->cmds[i]->flg)
	{
		ft_printf("memory problems in parser \n");
		return (exit_status(1, 1));
	}
	inter->cmds[i]->flg[arg] = NULL;
	while (*list && (*list)->token != PIPE)
	{
		if (arg == 0)
		{
			while (*list && (*list)->token != PIPE)
				*list = (*list)->next;
		}
		else
			*list = make_flg(inter->cmds[i], *list, arg, lexer);
	}
	if (*list)
		*list = (*list)->next;
	return (0);
}

int	make_exec(t_exec *inter, t_lex **lexer)
{
	t_lex	*list;
	int		i;

	list = *lexer;
	i = 0;
	while (i < inter->max_cmds && list != NULL)
	{
		if (list->is_exp == 1)
			inter->cmds[i]->is_exp_one = 1;
		if (create_flags(inter, &list, i, lexer) != 0)
			return (1);
		i++;
	}
	return (0);
}

/* dividida en las 4 anteriores
int	make_exec(t_exec *inter, t_lex **lexer)
{
	t_lex	*list;
	int		i;
	int		arg;

	list = *lexer;
	i = 0;
	arg = 0;
	while (i < inter->max_cmds && list != NULL)
	{
		arg = count_arg(list);
		inter->cmds[i]->flg = (char **)malloc((arg + 1) * sizeof (char *));
		if (!inter->cmds[i]->flg)
		{
			ft_printf("memory problems in parser \n");
			return (exit_status(1, 1));
		}
		inter->cmds[i]->flg[arg] = NULL;
		while (list && list->token != PIPE)
		{
			if (arg == 0)
			{
				while (list && list->token != PIPE)
					list = list->next;
			}
			else
				list = make_flg(inter->cmds[i], list, arg, lexer);
		}
		if (list)
			list = list->next;
		i++;
	}
	return (0);
}*/
