/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:49:14 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/02 10:05:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_error.h"

t_env	*dup_matrix_env(char **envp)
{
	t_env	*dup;
	int		i;

	i = 0;
	dup = init_enve(envp);
	while (envp[i])
	{
		dup->env[i] = ft_strdup(envp[i]);
		if (!dup->env[i])
			return (free_matrix(dup->env, i), free(dup), NULL);
		dup->export[i] = ft_strdup_export(dup->env[i]);
		if (!dup->export[i])
			return (free_matrix(dup->export, i), \
					free_matrix(dup->env, i), \
							free(dup), NULL);
		i++;
	}
	return (dup);
}

/******************************************************************************/
/**
   @file arg_fin_env_var.c
   @brief arg_fin_env_var() finds a variable in an environment

   @param[in] environs: a **char variable with all enviromental variables
   @param[in] var: The variable name to look for

   @details
   Loops the environment. For each var check if var name appears in it.        
   When match returns the pointer to found variable, Otherwise returns NULL

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
/*
char	*arg_fin_env_var(char **env, char *var)
{
	int		len;
	char	*result;

	len = ft_strlen(var);
	while (*env != NULL)
	{
		result = ft_strnstr(*env, var, len);
		if (result)
			return (*env);
		env++;
	}
	//ft_error_print(ERR006, __func__, __LINE__);
	return (NULL);
}
*/
char	*arg_fin_env_var(char **env, char *var)
{
	int		len;

	len = ft_strlen(var);
	while (*env != NULL)
	{
		if (ft_strncmp(*env, var, len) == 0 && (*env)[len] == '=')
		{
			return (*env);
		}
		env++;
	}
	return (NULL);
}

/******************************************************************************/
/**
   @file arg_val_var.c
   @brief arg_val_var() returns the text after '=' from an enviromental var

   @param[in]  *vars: an enviromental variable wiht this format:
            NAME=VALUE

   @details
   Split the variable definition by char '='.  stack couting how many values
   are lower or equal than current (external loop node) node's value.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
char	*arg_val_var(char *var)
{
	char	**var_parts;
	char	*result;

	var_parts = ft_split(var, '=');
	if (var_parts)
	{
		result = var_parts[1];
		free(var_parts[0]);
		free(var_parts);
		return (result);
	}
	free(var_parts);
	return (NULL);
}

char	**ft_add_env(char *str, char **env)
{
	char	**tmp;
	int		i;
	int		sust_flag;

	sust_flag = 0;
	i = 0;
	tmp = malloc(sizeof(char *) * (ft_array_len(env) + 2));
	if (!tmp)
		return (NULL);
	while (env[i])
	{
		if (ft_strcmp_env(env[i], str) == 0)
		{
			tmp[i] = ft_strdup(str);
			sust_flag = 1;
		}
		else
			tmp[i] = ft_strdup(env[i]);
		i++;
	}
	if (sust_flag == 0)
		tmp[i++] = ft_strdup(str);
	tmp[i] = NULL;
	ft_matrix_free(env);
	return (tmp);
}

int	ft_strcmp_env(char *env, char *str)
{
	int	i;

	i = 0;
	while (env[i] != '=' && str[i] != '\0')
	{
		if (env[i] != str[i])
			return (env[i] - str[i]);
		i++;
	}
	if (env[i] == '=' && str[i] == '\0')
		return (0);
	return (env[i] - str[i]);
}
