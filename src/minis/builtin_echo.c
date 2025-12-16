/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:05:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/05/02 09:20:45 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	flag_n(char *flag)
{
	int	i;

	i = 0;
	if (ft_strlen(flag) <= 1)
		return (0);
	if (flag[0] != '-')
		return (0);
	i++;
	while (flag[i])
	{
		if (flag[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	builtin_echo(char **args)
{
	int	i;
	int	flag;

	i = 1;
	if (!args[1])
		ft_printf("\n");
	else
	{
		flag = flag_n(args[i]);
		while (args[i] && flag == 1)
		{
			i++;
			flag = flag_n(args[i]);
		}
		if (flag == 1 && !args[i + 1])
			return (0);
		else if (flag == 0 && args[i] && flag_n(args[i - 1]) == 1)
			ft_print_matrix(args, i);
		else if (flag == 0 && args[i])
		{
			ft_print_matrix(args, i);
			ft_printf("\n");
		}
	}
	return (0);
}
