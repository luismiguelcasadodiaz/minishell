/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:06:06 by luicasad          #+#    #+#             */
/*   Updated: 2024/05/02 09:20:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp_export(char *export, char *str)
{
	int	i;

	i = 0;
	while (export[i] != '=' && str[i] != '\0')
	{
		if (export[i] != str[i])
			return (export[i] - str[i]);
		i++;
	}
	if (export[i] == '=' && str[i] == '\0')
		return (0);
	return (export[i] - str[i]);
}

t_env	*ft_join_env_export(char *str, t_env *env)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || flag == 1)
		{
			flag = 1;
			str[i] = str[i + 1];
		}
		i++;
	}
	str[i] = '\0';
	env->env = ft_join_env(str, env->env);
	env->export = ft_join_export(str, env->export);
	return (env);
}

t_env	*ft_add_env_export(char *str, t_env *env)
{
	env->env = ft_add_env(str, env->env);
	env->export = ft_add_export(str, env->export);
	return (env);
}

int	builtin_export(char **args, t_env *env)
{
	int	i;

	i = 1;
	if (!args[1])
		ft_print_export(env->export);
	else
	{
		while (args[i])
		{
			if (check_format_export(args[i]) == 0)
				env = ft_add_env_export(args[i], env);
			else if (check_format_export(args[i]) == 3)
				env = ft_join_env_export(args[i], env);
			else if (check_format_export(args[i]) == 2)
				env->export = ft_add_export(args[i], env->export);
			else
			{
				ft_printf_fd(2, \
				"minishell: export: `%s': not a valid identifier\n", args[i]);
				exit_status(1, 1);
			}
			i++;
		}
	}
	return (exit_status(0, 0));
}
