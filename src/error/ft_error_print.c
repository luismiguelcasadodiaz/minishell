/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:43:45 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/04 18:23:28 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_error.h"
#include <stdio.h>

int	ft_error_print_ret(int e, const char *f, int l)
{
	ft_error_print(e, f, l);
	return (e);
}

void	ft_error_print(int e, const char *f, int l)
{
	char	*linn;
	char	*func;
	char	*line;
	char	*loca;
	char	*text;

	linn = ft_itoa(l);
	line = ft_strjoin(linn, "-> ");
	free(linn);
	func = ft_strjoin(f, ":");
	loca = ft_strjoin(func, line);
	free(func);
	free(line);
	linn = ft_itoa(e);
	line = ft_strjoin(" [error ", linn);
	free(linn);
	linn = ft_strjoin(loca, line);
	free(loca);
	free(line);
	loca = ft_strjoin(linn, "] ");
	free(linn);
	text = ft_strjoin(loca, ft_error_str(e));
	perror(loca);
	free(loca);
	free(text);
}

char	*ft_error_text(int e, const char *f, int l)
{
	char	*linn;
	char	*func;
	char	*line;
	char	*loca;
	char	*text;

	linn = ft_itoa(l);
	line = ft_strjoin(linn, "-> ");
	free(linn);
	func = ft_strjoin(f, ":");
	loca = ft_strjoin(func, line);
	free(func);
	free(line);
	linn = ft_itoa(e);
	line = ft_strjoin(" [error ", linn);
	free(linn);
	linn = ft_strjoin(loca, line);
	free(loca);
	free(line);
	loca = ft_strjoin(linn, "] ");
	free(linn);
	text = ft_strjoin(loca, ft_error_str(e));
	free(loca);
	return (text);
}
