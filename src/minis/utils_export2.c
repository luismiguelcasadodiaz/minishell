/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:39:03 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/14 16:39:29 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_format_export(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while ((ft_isalpha(str[i]) == 1 || str[i] == '_') && str[i] != '\0')
		i++;
	if (ft_strncmp(&str[i], "+=", 2) == 0 && i != 0)
		return (3);
	if (str[i] == '\0')
		return (2);
	if (str[i] != '=' || i == 0)
		return (1);
	return (0);
}

void	ft_print_export(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		ft_printf("declare -x %s\n", matrix[i++]);
}

static size_t	ft_strlen_until_char(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	return (len);
}

static int	ft_c_or_r(char *str, char **export, char **tmp, int len)
{
	int		i;
	int		sust_flag;

	sust_flag = 0;
	i = 0;
	while (export[i])
	{
		if (ft_strncmp(export[i], str, len) == 0 && (export[i][len] == '\0'
			|| export[i][len] == '='))
		{
			if (str[len] == '=')
				tmp[i] = ft_strdup_export(str);
			else
				tmp[i] = ft_strdup(export[i]);
			sust_flag = 1;
		}
		else
			tmp[i] = ft_strdup(export[i]);
		i++;
	}
	return (sust_flag);
}

char	**ft_add_export(char *str, char **export)
{
	char	**tmp;
	int		i;
	int		sust_flag;
	int		len;

	sust_flag = 0;
	i = 0;
	len = ft_strlen_until_char(str, '=');
	tmp = malloc(sizeof(char *) * (ft_array_len(export) + 2));
	if (!tmp)
		return (NULL);
	sust_flag = ft_c_or_r(str, export, tmp, len);
	i = ft_array_len(export);
	if (sust_flag == 0)
		tmp[i++] = ft_strdup_export(str);
	tmp[i] = NULL;
	ft_matrix_free(export);
	return (tmp);
}
