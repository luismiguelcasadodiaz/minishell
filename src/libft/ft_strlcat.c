/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:54 by luicasad          #+#    #+#             */
/*   Updated: 2023/09/27 19:52:58 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ft_strlcat concatenates the input string into a destination string.        */
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
/*  The total length of the string tried to create. dst_len + src_len.        */
/*                                                                            */
/*  The idea behind this simplifies truncations detection.                    */
/*  If the return value dst_len + src_len >= dstsize, the output string has   */
/*  been truncated.  It is the caller's responsibility to handle this.        */
/*                                                                            */
/* OPERATION:                                                                 */
/*  CASE A : dst_len < dst_siz . there is available space for src chars       */
/*  dst [ddd0      ]                                                          */
/*      [0123456789]                                                          */
/*          ^      dst_size = 10                                              */
/*    dst_len = 3                                                             */
/*                                                                            */
/*   Space available is (st_size - dst_len - 1), being the -1 required for    */
/*   null-termination char.                                                   */
/*                                                                            */
/*   strlcat loops src till it fills available space or tille src finish.     */
/*   As space available is in chars and src_idx index is base zero the        */
/*   verification os space exhaustion is done wiht (<).                       */
/*   I this case we try to create dst_len + src_len. WE RETURN IT             */
/*                                                                            */
/*   After looping, functions null terminates dst.                            */
/*                                                                            */
/*                                                                            */
/*   strlcat caller will check if truncation happened.                        */
/*                                                                            */
/*   Tuncation inside ft_strlcat happens when src does not fit in             */
/*                                                                            */
/*                       ------------------                                   */
/*                                                                            */
/*  CASE B : dst_len >= dst_siz . There is not space for src chars            */
/*  dst [ddddddddd0]                                                          */
/*      [0123456789]                                                          */
/*               ^ dst_size = 10                                              */
/*    dst_len = 9                                                             */
/*                                                                            */
/*  Not having available space NO WHILE IS REQUIRED.                          */
/*                                                                            */
/*   I this case we try to create dst_siz + src_len. WE RETURN IT             */
/*   strlcat caller will check if truncation happened.                        */
/*                                                                            */
/*   Tuncation inside ft_strlcat happens when src does not fit in             */
/*                                                                            */
/*                       ---------------------                                */
/*                                                                            */
/*  CASE B2: dst_len >= dst_siz . There is not space for src chars            */
/*                                                                            */
/*    This situation, of course not comming  from a 42 student,               */
/*    may occur. Being an inconsistent one, strlcat does nothing, aside       */
/*    returning the size str tried to create.                                 */
/*                                                                            */
/*       012345678901234567                                                   */
/*  dst [dddddddddddddddddd0                                                  */
/*      [0123456789]                                                          */
/*               ^ dst_size = 10                                              */
/*    dst_len = 18                                                            */
/*                                                                            */
/*  Not having available space NO WHILE IS REQUIRED.                          */
/*                                                                            */
/*   I this case we try to create dst_siz + src_len. WE RETURN IT             */
/*   strlcat caller will check if truncation happened.                        */
/*                                                                            */
/*   Tuncation inside ft_strlcat happens when src does not fit in             */
/*                                                                            */
/* USAGE                                                                      */
/*  char	*path;                                                            */
/*  char	path[40];                                                         */
/*  ...                                                                       */
/*  path_len = ft_strlen(path); OR path_len = sizeof(path)                    */
/*  home_len = ft_strlcat(path, home, path_len)                               */
/*  if (home_len > path_len)                                                  */
/*      return (ENAMETOOLONG);                                                */
/*                                                                            */
/* INSPIRATION                                                                */
/*  https://gratisoft.us/todd/papers/strlcpy.html                             */
/*                                                                            */
size_t	ft_strlcat(char *dst, const char *src, size_t dst_siz)
{
	size_t	src_len;
	size_t	src_idx;
	size_t	dst_len;
	size_t	dst_idx;
	size_t	tried;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	dst_idx = dst_len;
	src_idx = 0;
	if (dst_len < dst_siz)
	{
		while (src_idx < (dst_siz - dst_len -1) && (src[src_idx] != '\0'))
			dst[dst_idx++] = src[src_idx++];
		dst[dst_idx] = '\0';
		tried = dst_len + src_len;
	}
	else
	{
		tried = dst_siz + src_len;
	}
	return (tried);
}
