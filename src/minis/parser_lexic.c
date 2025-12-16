/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:21 by maria-nm          #+#    #+#             */
/*   Updated: 2024/04/25 12:20:44 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MSSG_ERR_NL "syntax error near unexpected token `newline'\n"
#define MSSG_ERR_PIPE "syntax error near unexpected token `|'\n"
#define MSSG_ERR_LESS "syntax error near unexpected token `<'\n"
#define MSSG_ERR_LESS_LESS "syntax error near unexpected token `<<'\n"
#define MSSG_ERR_GREAT "syntax error near unexpected token `>'\n"
#define MSSG_ERR_GREAT_GREAT "syntax error near unexpected token `>>'\n"

void	parser_error(int error)
{
	if (error == SYNTAX_NL)
		ft_printf_fd(2, "minishell: %s", MSSG_ERR_NL);
	else if (error == SYNTAX_PIPE)
		ft_printf_fd(2, "minishell: %s", MSSG_ERR_PIPE);
	else if (error == SYNTAX_LESS)
		ft_printf_fd(2, "minishell: %s", MSSG_ERR_LESS);
	else if (error == SYNTAX_LESS_LESS)
		ft_printf_fd(2, "minishell: %s", MSSG_ERR_LESS_LESS);
	else if (error == SYNTAX_GREAT)
		ft_printf_fd(2, "minishell: %s", MSSG_ERR_GREAT);
	else if (error == SYNTAX_GREAT_GREAT)
		ft_printf_fd(2, "minishell: %s", MSSG_ERR_GREAT_GREAT);
}

int	check_duplicate_tokens(t_lex *l)
{
	if (l->token == LESS || l->token == LESS_LESS
		|| l->token == GREAT || l->token == GREAT_GREAT)
	{
		if (l->next == NULL)
		{
			parser_error(SYNTAX_NL);
			return (1);
		}
		else if (l->next->token != NONE && l->next->token != STRING
			&& l->next->token != STRING_ONE_Q && l->next->token != STRING_TWO_Q)
		{
			if (l->next->token == PIPE)
				parser_error(SYNTAX_PIPE);
			else if (l->next->token == LESS)
				parser_error(SYNTAX_LESS);
			else if (l->next->token == LESS_LESS)
				parser_error(SYNTAX_LESS_LESS);
			else if (l->next->token == GREAT)
				parser_error(SYNTAX_GREAT);
			else if (l->next->token == GREAT_GREAT)
				parser_error(SYNTAX_GREAT_GREAT);
			return (1);
		}
	}
	return (0);
}

int	check_pipe_error(t_lex *lexer)
{
	if (lexer->token == PIPE)
	{
		if (lexer->prev == NULL)
		{
			parser_error(SYNTAX_PIPE);
			return (1);
		}
		if (lexer->next && lexer->next->token == PIPE)
		{
			parser_error(SYNTAX_PIPE);
			return (1);
		}
		else if (!lexer->next)
		{
			parser_error(SYNTAX_NL);
			return (1);
		}
	}
	return (0);
}

int	check_syntax_error(t_lex *lexer)
{
	while (lexer)
	{
		if (lexer->token != NONE)
		{
			if (check_duplicate_tokens(lexer) == 1
				|| check_pipe_error(lexer) == 1)
			{
				exit_status(1, 258);
				return (SYNTAX_ERR);
			}
		}
		lexer = lexer->next;
	}
	return (0);
}
