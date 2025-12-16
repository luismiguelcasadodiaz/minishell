/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/19 10:42:03 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_memset -- fill a byte string with a byte value                          */
/* The ft_memset() function writes len bytes of value c to the string b.      */
/* The c value is previously converted to an unsigned char                    */
/*                                                                            */
/* The default behavior of the memset function when the last argument holds   */
/* an integer bigger than the first argument length is to pad the first       */
/* argument with the value specified in the second argument, until the length */
/* of the first argument is equal to the last argument.                       */
/*                                                                            */
/* The default behaviour potentially overwrites memory in adjacent or         */
/* unrelated areas of your program's memory. This behavior can lead to        */
/* undefined behavior, which means your program's behavior becomes            */
/* unpredictable, and it may crash or produce incorrect results.              */
/*                                                                            */
/* Therefore, it's essential to ensure that you provide a valid and           */
/* appropriate value for num, not exceeding the size of the memory block you  */
/* are working with. If you need to fill only part of a larger memory block,  */
/* you should specify the correct number of bytes to fill and ensure that the */
/* operation stays within the bounds of the allocated memory.                 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	fill;
	size_t			idx;

	fill = (unsigned char) c;
	idx = 0;
	while (len--)
		((unsigned char *)b)[idx++] = fill;
	return (b);
}
/* ===========         When tested.............                               */
/*                                                               
void	test_num(void *b, int c, size_t len)
{
	printf("I >%d<,", *(int *)ft_memset(b, c, len));
	printf("he >%d<\n",*(int *)memset(b, c, len));
}

int	main(void)
{
	int		num;
	num = 2147111111;
	test_num(&num, 0, 0);
	test_num(&num, 0, 1);
	test_num(&num, 0, 2);
	test_num(&num, 0, 3);
	test_num(&num, 0, 4);
	return (0);
}
*/

/*                                                                            */
/* ===============       i got this results.......                            */
/*
I  >2147111111<, he >2147111111<
I  >2147110912<, he >2147110912<
I  >2147090432<, he >2147090432<
I  >2130706432<, he >2130706432<
I  >0<, he >0<
*/

/* ===============       using BC command i notice .......                    */
/* the LSB (less significative byte) of an integer fits in the lower memory   */
/* Adress                                                                     */
/*
2147111111
1111111111110100101000011000111
2147110912
1111111111110100101000000000000
2147090432
1111111111110100000000000000000
2130706432
1111111000000000000000000000000
0
0000000000000000000000000000000
*/
