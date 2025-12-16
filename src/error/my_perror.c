/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:42:11 by luicasad          #+#    #+#             */
/*   Updated: 2024/05/02 11:53:24 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	my_perror(char *a, char *b)
{
	char	*j;
	char	*i;

	if (b)
	{
		j = ft_strjoin(a, b);
		i = ft_strjoin("minishell 1: ", j);
		ft_printf_fd(2, "%s\n", i);
		free(j);
		free(i);
	}
	else
	{
		j = ft_strjoin("minishell 22: ", a);
		perror(j);
		free(j);
	}
}
