/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:29:17 by maria-nm          #+#    #+#             */
/*   Updated: 2024/05/31 11:31:28 by maria-nm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_get_hex_fd(unsigned long nb, int test, int fd)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nb >= 16 && test != -1 && i != -1)
	{
		test = ft_get_hex_fd(nb / 16, test, fd);
		i = ft_test_write_fd(test, i);
		if (i == -1)
			return (i);
		test = ft_get_hex_fd(nb % 16, test, fd);
		i = ft_test_write_fd(test, i);
		if (i == -1)
			return (i);
	}
	else
	{
		test = ft_printchar_fd(base[nb], fd);
		i = ft_test_write_fd(test, i);
	}
	return (i);
}

int	ft_printundhex_fd(unsigned int nb, int test, int fd)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nb >= 16 && test != -1 && i != -1)
	{
		test = ft_printundhex_fd(nb / 16, test, fd);
		i = ft_test_write_fd(test, i);
		if (i == -1)
			return (i);
		test = ft_printundhex_fd(nb % 16, test, fd);
		i = ft_test_write_fd(test, i);
		if (i == -1)
			return (i);
	}
	else
	{
		test = ft_printchar_fd(base[nb], fd);
		i = ft_test_write_fd(test, i);
	}
	return (i);
}

int	ft_printuphex_fd(unsigned int nb, int test, int fd)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16 && test != -1 && i != -1)
	{
		test = ft_printuphex_fd(nb / 16, test, fd);
		i = ft_test_write_fd(test, i);
		if (i == -1)
			return (i);
		test = ft_printuphex_fd(nb % 16, test, fd);
		i = ft_test_write_fd(test, i);
		if (i == -1)
			return (i);
	}
	else
	{
		test = ft_printchar_fd(base[nb], fd);
		i = ft_test_write_fd(test, i);
	}
	return (i);
}

int	ft_printpnt_fd(unsigned long pointer, int fd)
{
	int	count;
	int	aux;

	aux = 0;
	count = ft_printstr_fd("0x", fd);
	if (count == -1)
		return (count);
	aux = ft_get_hex_fd(pointer, 0, fd);
	if (aux != -1)
		count += aux;
	else
		return (aux);
	return (count);
}
