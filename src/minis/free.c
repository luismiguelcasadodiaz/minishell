/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:30:50 by maria-nm          #+#    #+#             */
/*   Updated: 2024/04/29 12:38:40 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"
#include "libft.h"

char	**free_matrix(char **matrix, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)matrix[j]);
	}
	free(matrix);
	return (NULL);
}

void	ft_matrix_free(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_env(t_env *enve)
{
	enve->env = free_matrix(enve->env, ft_array_len(enve->env));
	enve->export = free_matrix(enve->export, ft_array_len(enve->export));
	if (enve->env == NULL && enve->export == NULL)
		free(enve);
	else
		ft_printf("error al liberar enve");
}
