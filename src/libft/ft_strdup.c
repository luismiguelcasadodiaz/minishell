/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/24 13:31:32 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*                                                                            */
/* The ft_strdup() function returns a pointer to a new string which is a      */
/* duplicate of the string s.                                                 */
/* Memory for the new string is obtained with malloc(), and can be freed with */
/* free()                                                                     */
/*                                                                            */
/* RETURNS :                                                                  */
/* On success, the ft_strdup() function returns a pointer to the duplicated   */
/* string.                                                                    */
/* It returns NULL if insufficient memory was available, with errno set to    */
/* indicate the error.                                                        */
/*                                                                            */
/* OPERATION:                                                                 */
/*  s_size + 1 to add space for the string termination char                   */
char	*ft_strdup(const char *s)
{
	size_t	s_size;
	char	*dup;

	s_size = ft_strlen(s);
	dup = (char *)malloc(s_size + 1);
	if (dup == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	else
		return ((char *)ft_memcpy(dup, s, s_size +1));
}
