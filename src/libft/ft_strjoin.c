/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/10/02 19:13:47 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_strjoin() concatenates in a new string the prefix and the suffix args   */
/*                                                                            */
/* GETS                                                                       */
/*  s1: the prefix string.                                                    */
/*  s2: the suffix string.                                                    */
/*                                                                            */
/* RETURNS                                                                    */
/*  The new string resulting from s1 + s2  concatenation or NULL if malloc    */
/*  fails.                                                                    */
/*                                                                            */
/* OPERATION                                                                  */
/*  calculate prefix and suffix length and resulting string length.           */
/*  allocate memory for resulting string.                                     */
/*  copy the prefix to the resulting string                                   */
/*  concatenate the suffix to the resulting string.                           */

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	size_t	s1s2_size;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	s1s2_size = s1_size + s2_size + 1;
	join = (char *)malloc(s1s2_size);
	if (join != NULL)
	{
		ft_strlcpy(join, s1, s1_size + 1);
		ft_strlcat(join, s2, s1s2_size);
	}
	return (join);
}
