/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/28 11:27:44 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_strlcpy copies the input string into a destination string.              */
/* If the destination buffer, limited by its size, isn't large enough to hold */
/* the src the resulting  string  is  truncated  (but  it  is  guaranteed     */
/* to be null-terminated).                                                    */
/*                                                                            */
/* They return the length of the total string they tried to create.           */
/*                                                                            */
/* GETS                                                                       */
/*  dst a pointer to a buffer containing a null-terminated string             */
/*  src a pointer to a null-terminated string                                 */
/*  dst_size buffer'size to concatenate src with. (no dst string's len)       */
/*                                                                            */
/* RETURNS:                                                                   */
/*  The total length of the string tried to create.  src_len.                 */
/*                                                                            */
/*  The idea behind this simplifies truncations detection.                    */
/*  If the return value  src_len >= dstsize,          the output string has   */
/*  been truncated.  It is the caller's responsibility to handle this.        */
/*                                                                            */
/* OPERATION:                                                                 */
/*  CASE A : src_len < dst_siz . there is available space for src chars       */
/*  src [sss0      ]                                                          */
/*          ^                                                                 */
/*    src_len = 3                                                             */
/*  dst [          ]       ==>    [sss0      ]                                */
/*       0123456789                                                           */
/*                 dst_size = 10                                              */
/*                                                                            */
/*   Space available is (dst_size - 1), being the -1 required for null-termi- */
/*   nation char. ATTENTION HERE: dst_size is unsigned long. When is zero the */
/*   expression (dst_size - 1) becomes 18446744073709551615 and idx alwways   */
/*   is smaller, allowing while to start coping incorreclty. This is the      */
/*   reasons for the if (dst_size)                                            */
/*                                                                            */
/*   ft_strlcpy loops src till it fills available space or tille src finish.  */
/*   As space available is in chars and src_idx index is base zero the        */
/*   verification os space exhaustion is done wiht (<).                       */
/*   I this case we try to create  src_len. WE RETURN IT                      */
/*                                                                            */
/*   After looping, functions null terminates dst.                            */
/*                                                                            */
/*   ft_strlcpy caller will check if truncation happened.                     */
/*                                                                            */
/*   Tuncation inside ft_strlcpy happens when src does not fit in             */
/*                                                                            */
/*                       ------------------                                   */
/*                                                                            */
/*  CASE B : src_len >= dst_siz . There is not space for src chars            */
/*       012345678901234567                                                   */
/*  src [sssssssssssssssss0]                                                  */
/*                       ^                                                    */
/*                      src_len = 17                                          */
/*       0123456789                                                           */
/*  dst [          ]       ==>    [sssssssss0]                                */
/*                 dst_size = 10                                              */
/*                                                                            */
/*   I this case we try to create src_len. WE RETURN IT                       */
/*   ft_strlcpy caller will check if truncation happened.                     */
/*                                                                            */
/*   Tuncation inside ft_strlcpy happens when src does not fit in             */
/*                                                                            */
/*                       ------------------                                   */
/*                                                                            */
/*  CASE B2: src_len >= dst_siz . There is not space for src chars            */
/*       012345678901234567                                                   */
/*  src [sssssssssssssssss0]                                                  */
/*                       ^                                                    */
/*                      src_len = 17                                          */
/*       0123456789                                                           */
/*  dst []       ==>    []                                                    */
/*                 dst_size = 0                                               */
/*                                                                            */
/*  Not having available space NO WHILE IS REQUIRED. "if (dst_size)           */
/*                                                                            */
/* USAGE                                                                      */
/*  char	*path;                                                            */
/*  char	path[40];                                                         */
/*  ...                                                                       */
/*  path_len = ft_strlen(path); OR path_len = sizeof(path)                    */
/*  home_len = ft_strlcpy(path, home, path_len)                               */
/*  if (home_len > path_len)                                                  */
/*      return (ENAMETOOLONG);                                                */
/*                                                                            */
/* INSPIRATION                                                                */
/*  https://gratisoft.us/todd/papers/strlcpy.html                             */
/*                                                                            */
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	idx;

	src_len = ft_strlen(src);
	if (dst_size)
	{
		idx = 0;
		while (idx < src_len && (idx < (dst_size - 1)))
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (src_len);
}
