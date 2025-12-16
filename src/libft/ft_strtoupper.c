/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:14:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/05/14 11:27:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//ft_strtoupper() Returns the str argument's content to upper case;
char	*ft_strtoupper(char *str)
{
	char	*result;
	char	*letter;

	result = ft_strdup(str);
	letter = result;
	while (*letter)
	{
		*letter = ft_toupper(*letter);
		letter++;
	}
	return (result);
}
/*
int	main(int argc, char **argv)
{
	printf("%s --> %s", argv[1], ft_strtoupper(argv[1]));
	return (0);
}*/
