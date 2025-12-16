/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_decode_e.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:36:23 by luicasad          #+#    #+#             */
/*   Updated: 2024/03/09 13:55:25 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"

static	char	*decode_000_010(int e)
{
	if (e == ERR001)
		return ("Environment variable has not char(=)");
	if (e == ERR002)
		return ("No sach file or directory or Permission denied");
	if (e == ERR003)
		return ("The command does not exits in current path");
	if (e == ERR004)
		return ("PATH variable value has not char(:)");
	if (e == ERR005)
		return ("Memory allocation failed");
	if (e == ERR006)
		return ("Environment variable not found in current environment");
	if (e == ERR007)
		return ("dup() failed");
	if (e == ERR008)
		return ("Permission denied");
	if (e == ERR010)
		return ("open() failed");
	return (ft_strjoin("Unknow error ", ft_itoa(e)));
}

char	*ft_error_decode_e(int e)
{
	if ((-10 <= e) && (e <= 0))
		return (decode_000_010(e));
	if (e == ERR020)
		return ("fork() failed");
	if (e == ERR021)
		return ("pipe() failed");
	if (e == ERR050)
		return ("t_pipex_args has not available slots for more commands");
	if (e == ERR051)
		return ("execve() failed execution. Check flags used with command");
	if (e == ERR126)
		return ("Permission denied");
	if (e == ERR127)
		return ("command not found");
	return (ft_strjoin("Unknow error ", ft_itoa(e)));
}
