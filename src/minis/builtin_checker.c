/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:14:06 by luicasad          #+#    #+#             */
/*   Updated: 2024/06/25 00:34:40 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	builtin_exe(char *arg, char **args, t_env *env)
{
	int	result;

	result = 0;
	if (!ft_strncmp(arg, "cd", 2) && ft_strlen(arg) == 2)
		result = builtin_cd(args, &(env)->env);
	else if (!ft_strncmp(arg, "echo", 4) && ft_strlen(arg) == 4)
		result = builtin_echo(args);
	else if (!ft_strncmp(arg, "env", 3) && ft_strlen(arg) == 3)
		result = builtin_env(env->env);
	else if (!ft_strncmp(arg, "exit", 4) && ft_strlen(arg) == 4)
		result = builtin_exit(args);
	else if (!ft_strncmp(arg, "export", 6) && ft_strlen(arg) == 6)
		result = builtin_export(args, env);
	else if (!ft_strncmp(arg, "pwd", 3) && ft_strlen(arg) == 3)
		result = builtin_pwd();
	else if (!ft_strncmp(arg, "unset", 5) && ft_strlen(arg) == 5)
		result = builtin_unset(args, env);
	return (result);
}

int	builtin_check(char *arg)
{
	int		result;

	if (arg == NULL)
		return (0);
	result = 0;
	if (!ft_strncmp(arg, "cd", 2) && ft_strlen(arg) == 2)
		result = 1;
	else if (!ft_strncmp(arg, "echo", 4) && ft_strlen(arg) == 4)
		result = 1;
	else if (!ft_strncmp(arg, "env", 3) && ft_strlen(arg) == 3)
		result = 1;
	else if (!ft_strncmp(arg, "exit", 4) && ft_strlen(arg) == 4)
		result = 1;
	else if (!ft_strncmp(arg, "export", 6) && ft_strlen(arg) == 6)
		result = 1;
	else if (!ft_strncmp(arg, "pwd", 3) && ft_strlen(arg) == 3)
		result = 1;
	else if (!ft_strncmp(arg, "unset", 5) && ft_strlen(arg) == 5)
		result = 1;
	return (result);
}
