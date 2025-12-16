/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:06:30 by luicasad          #+#    #+#             */
/*   Updated: 2024/05/02 09:20:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_generate_new_env(char **args, char **env, int j, int i)
{
	while (env[j])
	{
		if (ft_strcmp_env(env[j], args[i]) == 0)
		{
			free(env[j]);
			while (env[j])
			{
				env[j] = env[j + 1];
				j++;
			}
		}
		if (env[j])
			j++;
	}
}

int	builtin_unset(char **args, t_env *env)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		if (check_cmd(args[i]))
		{
			ft_printf_fd(2, "minishell: unset: `%s': not a valid identifier\n", \
			args[i]);
			exit_status(1, 1);
			return (1);
		}
		j = 0;
		ft_generate_new_env(args, env->env, j, i);
		ft_generate_new_env(args, env->export, j, i);
		i++;
	}
	return (0);
}
