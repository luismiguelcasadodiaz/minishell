/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:14:06 by luicasad          #+#    #+#             */
/*   Updated: 2024/05/21 18:35:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include "ft_error.h"
#include "ft_printf.h"

void	my_close(int who, int *fd, const char *func, int line)
{
	int		r;
	char	*loc;
	char	*txt;
	char	*aux;
	char	*aux2;

	r = close(*fd);
	if (r)
	{
		txt = ft_strjoin_int("Error closing file ", *fd);
		loc = ft_strjoin_int(" Process[", who);
		aux = ft_strjoin(loc, "] ");
		free(loc);
		aux2 = ft_strjoin_int(aux, line);
		free(aux);
		aux = ft_strjoin(aux2, " ");
		free(aux2);
		loc = ft_strjoin(func, aux);
		free(aux);
		my_perror(loc, txt);
		free(txt);
		free(loc);
	}
	else
		*fd = -1;
}
