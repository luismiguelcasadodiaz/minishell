/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:05:59 by luicasad          #+#    #+#             */
/*   Updated: 2024/05/02 09:20:13 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
int	builtin_exit(int argc, char **args, char ***environ)
{
	if (!ft_strncmp(args[0], "exit", 4))
	{
		ft_printf("exit\n");
		exit (exit_status(0, 0));
	}
	else
	{
		ft_printf("minishell: %s: command not found [borrar =>%d %s\n", \
		args[0], argc, *environ[0]);
		return (0);
	}
}
*/
static int	is_numeric(const char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str && *str != ' ' )
	{
		if (!ft_isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

static const char	*skip_whitespace_and_sign(const char *str, int *sign)
{
	*sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

static long long	ft_atoll(const char *str, int *overflow)
{
	long long	res;
	int			sign;
	int			max_last_digit;

	res = 0;
	sign = 1;
	str = skip_whitespace_and_sign(str, &sign);
	if (sign == 1)
		max_last_digit = 7;
	else
		max_last_digit = 8;
	while (*str && isdigit(*str))
	{
		if (res > LLONG_MAX / 10
			|| (res == LLONG_MAX / 10 && (*str - '0') > max_last_digit))
		{
			*overflow = 1;
			if (sign == 1)
				return (LLONG_MAX);
			return (LLONG_MIN);
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

static int	exit_255(char *args)
{
	int	exit;

	//ft_printf_fd(2, "exit\n");
	ft_printf_fd(2, MSSG_EXIT_NUM_ERR, args);
	exit = 2;
	return (exit);
}

int	builtin_exit(char **args)
{
	long long	code;
	int			overflow;

	overflow = 0;
	if (!args[1] || (ft_strlen(args[1]) == 2 && !ft_strncmp(args[1], "--", 2)))
	{
		//ft_printf_fd(2, "exit\n");
		exit(exit_status(0, 0));
	}
	else if (is_numeric(args[1]))
	{
		code = ft_atoll(args[1], &overflow);
		if (overflow)
			exit(exit_255(args[1]));
		if (args[2])
		{
			//ft_printf_fd(2, "exit\n");
			ft_printf_fd(2, "minishell: exit: too many arguments\n");
			return (exit_status(1, 1));
		}
		//ft_printf_fd(2, "exit\n");
		exit(exit_status(1, code));
	}
	else
		exit(exit_255(args[1]));
}
