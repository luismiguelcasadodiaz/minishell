/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:27:13 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/05 17:28:18 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_enve(char **env)
{
	t_env	*dup;

	dup = malloc(sizeof(t_env));
	if (!dup)
		return (NULL);
	dup->env = malloc((array_len(env) + 1) * sizeof(char *));
	dup->env[array_len(env)] = NULL;
	if (!dup->env)
		return (free(dup), NULL);
	dup->export = malloc((array_len(env) + 1) * sizeof(char *));
	dup->export[array_len(env)] = NULL;
	if (!dup->export)
		return (free(dup->env), free(dup), NULL);
	return (dup);
}

char	*generate_terminal(void)
{
	char	*aux;
	char	*promp;
	char	*str;

	aux = getcwd(NULL, 0);
	if (!aux)
	{
		promp = ft_strdup(" No HOME :( :");
	}
	else
	{
		promp = ft_strdup("MINISHELL> ");
		if (!promp)
			return (free(aux), NULL);
	}
	str = readline(promp);
	return (free(aux), free(promp), str);
}

/*
char	*generate_terminal(t_env *env)
{
	char	*aux;
	char	*promp;
	char	*look_last_slash;
	char	*str;

	aux = getcwd(NULL, 0);
	if (!aux)
	{
		promp = ft_strdup(" No HOME :( :");
	}
	else
	{
		if (find_home(env->env) != NULL && \ 
		ft_strcmp(find_home(env->env), aux) == 0)
			promp = ft_strdup("~");
			//promp = ft_strdup("/Users/maria-nm");
		else if (ft_strcmp(aux, "/") == 0)
			promp = ft_strdup(aux);
		else
		{
			look_last_slash = ft_strrchr(aux, '/');
			ft_strlcat(look_last_slash, "> ", ft_strlen(look_last_slash) + 4);
			promp = ft_strdup(look_last_slash + 1);
		}
		if (!promp)
			return (free(aux), NULL);
	}
	str = readline(promp);
	return (free(aux), free(promp), str);
}
*/
int	str_to_cmd(char *str, t_exec *inter, t_env *env)
{
	int		status;
	t_lex	*lexer;

	lexer = NULL;
	inter->all_ok = 1;
	status = tokenizer(str, &lexer);
	if (status == 0)
		status = expansor(&lexer, env->env);
	if (status == 0)
	{
		status = check_list(&lexer);
		delete_white_space(&lexer);
	}
	if (status == 0)
		status = parser(inter, &lexer);
	if (status == 1)
		ft_printf_fd(2, MSSG_MEMORY_ERROR);
	lex_lstclear(&lexer);
	return (status);
}

void	init_terminal(t_env *env)
{
	char	*str;
	t_exec	inter;
	t_exec	*pinter;

	str = generate_terminal();
	pinter = &inter;
	while (str)
	{
		add_history(str);
		if (str_to_cmd(str, pinter, env) == 0 && pinter->all_ok)
		{
			init_signals(CHILDS);
			exit_status(1, executor(inter, &env));
			init_signals(PARENT);
		}
		free(str);
		str = generate_terminal();
	}
	if (isatty(STDIN_FILENO))
		write(2, "exit\n", 6);
	close(2);
	close(1);
	close(0);
	exit(exit_status(0, 0));
}
