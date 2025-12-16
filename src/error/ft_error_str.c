/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:21:12 by luicasad          #+#    #+#             */
/*   Updated: 2024/03/11 12:30:27 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include <string.h>
#include <stdio.h>
/******************************************************************************/
/**
   @file ft_error_str.c
   @brief ft_error_str () returns a error desccription. it blends de system 
   errors with the userdefined error;

   @param[in]  e: the error number to get a description for.

   @details
   if the error number is a user defined erroe code, then decode it. Otherwise
   returns the system error description returned by strerror.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/

char	*ft_error_str(int e)
{
	if (ERRnnn <= e && e <= ERR001)
		return (ft_error_decode_e(e));
	else
		return (strerror(e));
}
