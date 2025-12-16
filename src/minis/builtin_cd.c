/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:05:14 by luicasad          #+#    #+#             */
/*   Updated: 2024/05/02 09:17:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
static int	ft_chdir(char *direct, char ***env)
{
	char	*oldpwd;
	char	*pwd;
	char	*tmp;

	tmp = arg_fin_env_var(*env, "PWD");
	oldpwd = arg_val_var(tmp);
	free(tmp);
	if (chdir(direct) == -1)
	{
		ft_printf_fd(2, "minishell: cd: %s: ", direct);
		return (perror(NULL), exit_status(1, 1));
	}
	pwd = getcwd(NULL, 0);
	if (oldpwd)
	{
		tmp = ft_strjoin("OLDPWD=", oldpwd);
		*env = ft_add_env(tmp, *env);
		free(tmp);
		free(oldpwd);
	}
	if (pwd)
	{
		tmp = ft_strjoin("PWD=", pwd);
		*env = ft_add_env(tmp, *env);
		free(tmp);
		free(pwd);
	}
	return (exit_status(1, 0));
}
*/

static void	update_env_vars(char *oldpwd, char *pwd, char ***env)
{
	char	*tmp;

	tmp = NULL;
	if (oldpwd)
	{
		tmp = ft_strjoin("OLDPWD=", oldpwd);
		*env = ft_add_env(tmp, *env);
		free(tmp);
		free(oldpwd);
	}
	if (pwd)
	{
		tmp = ft_strjoin("PWD=", pwd);
		*env = ft_add_env(tmp, *env);
		free(tmp);
		free(pwd);
	}
}

static int	ft_chdir(char *direct, char ***env)
{
	char	*oldpwd;
	char	*pwd;
	char	*aux;

	aux = arg_fin_env_var(*env, "PWD");
	oldpwd = arg_val_var(aux);
	if (chdir(direct) == -1)
	{
		ft_printf_fd(2, "minishell: cd: %s: ", direct);
		free (oldpwd);
		return (perror(NULL), exit_status(1, 1));
	}
	pwd = getcwd(NULL, 0);
	update_env_vars(oldpwd, pwd, env);
	return (exit_status(1, 0));
}

int	builtin_cd(char **args, char ***environ)
{
	int	num_arg;

	num_arg = 0;
	while (args[num_arg])
		num_arg++;
	if (num_arg > 2)
	{
		ft_printf_fd(2, MSSG_CD_ERR);
		return (exit_status(1, 1));
	}
	else if (!args[1])
		return (ft_chdir(find_home(*environ), environ));
	else if (!*args[1])
		return (0);
	else if (ft_strcmp(args[1], "..") == 0)
		return (ft_chdir("..", environ));
	else if (ft_strcmp(args[1], ".") == 0)
		return (ft_chdir(".", environ));
	else if (ft_strcmp(args[1], "/") == 0)
		return (ft_chdir("/", environ));
	else if (ft_strcmp(args[1], "~") == 0)
		return (ft_chdir(find_home(*environ), environ));
	return (ft_chdir(args[1], environ));
}
