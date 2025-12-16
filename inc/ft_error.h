/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:52:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/05/20 10:34:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifdef __linux__
#  define MY_SYMBOL 1
#  define MY_ULL_MAX ULLONG_MAX
# elif __APPLE__
#  define MY_SYMBOL 2
#  define MY_ULL_MAX ULONG_LONG_MAX
# endif

# define EFD 2

enum e_my_errors
{
	ERR001 = -1,
	ERR002 = -2,
	ERR003 = -3,
	ERR004 = -4,
	ERR005 = -5,
	ERR006 = -6,
	ERR007 = -7,
	ERR008 = -8,
	ERR010 = -10,
	ERR020 = -20,
	ERR021 = -21,
	ERR050 = -50,
	ERR051 = -51,
	ERR126 = -126,
	ERR127 = -127,
	ERRnnn = -999
};

ssize_t	ft_write_c(char c);
ssize_t	ft_write_str(char *str);
ssize_t	ft_write_int_base(int num, int base, char *basechars, ssize_t *digits);
ssize_t	ft_write_uns_base(unsigned long long n,
			unsigned long long b,
			char *c,
			ssize_t *d);
ssize_t	ft_write_dec(int num);
ssize_t	ft_write_int(int num);
ssize_t	ft_write_ptr(void *num);
ssize_t	ft_write_uns(unsigned int num);
ssize_t	ft_write_hex_low(unsigned int num);
ssize_t	ft_write_hex_cap(unsigned int num);
int		ft_errorf(const char *fmt, ...);
//int	ft_errorf(const char *fmt, ...)__attribute__((format (printf, 1, 2)));
char	*ft_error_str(int e);
char	*ft_error_decode_e(int e);
void	ft_error_print(int e, const char *f, int l);
int		ft_error_print_ret(int e, const char *f, int l);
char	*ft_error_text(int e, const char *f, int l);
void	ft_error_exit(int e, const char *f, int l);
void	my_perror(char *a, char *b);
#endif
