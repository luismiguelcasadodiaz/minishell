/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:28:14 by maria-nm          #+#    #+#             */
/*   Updated: 2024/04/29 13:27:55 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	*ft_strdup_export(char *envp)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(ft_strlen(envp) + 3);
	if (!dup)
		return (NULL);
	while (envp[i] != '=' && envp[i] != '\0')
	{
		dup[i] = envp[i];
		i++;
	}
	if (envp[i] == '=')
	{
		dup[i] = envp[i];
		dup[++i] = C_TWO_QUOTE;
		while (envp[i] != '\0')
			(1 && (dup[i + 1] = envp[i]) && i++);
		dup[i + 1] = C_TWO_QUOTE;
		dup[i + 2] = '\0';
	}
	else
		dup[i] = '\0';
	return (dup);
}
/*
void	print_matrix(char **matrix, int i)
{
	while (matrix[i])
	{
		ft_printf("fila %d : %s\n", i, matrix[i]);
		i++;
	}
}*/

void	ft_print_matrix(char **matrix, int i)
{
	while (matrix[i])
	{
		ft_printf("%s", matrix[i]);
		if (matrix[i + 1])
			ft_printf(" ");
		i++;
	}
}

char	*find_home(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", ft_strlen("HOME=")) == 0)
			return (env[i] + ft_strlen("HOME="));
		i++;
	}
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	i = 0;
	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	while ((str[i] != '\0' || str1[i] != '\0'))
	{
		if (str[i] != str1[i])
			return (str[i] - str1[i]);
		i++;
	}
	return (0);
}
