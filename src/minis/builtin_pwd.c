/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:06:18 by luicasad          #+#    #+#             */
/*   Updated: 2024/05/09 19:24:17 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_error.h"

/******************************************************************************/
/**
  @file builtin_pwd.c
  @brief builtin_pwd() prints the value of an enviroment variable named PWD

  @param[in]  argc: number of tokens existing in the command line
  @param[in]  argv
   
  @details
  Bash reference manual states:
  Prints the absolute pathname of the current working directory. 
   With -P option, the pathname printed will not contain symbolic links. 
   With -L option, the pathname printed may contain symbolic links.

  Minishell subject states:
  pwd sin opciones.
  
  First if more than one token exits in the command line, return
  @returns
  The return status is zero unless:
 	a)  an error is encountered determining the name of the current directory
    b)  an invalid option is supplied.:  
******************************************************************************/

int	builtin_pwd(void)
{
	char	*path;

	path = NULL;
	path = getcwd(path, 0);
	ft_printf("%s\n", path);
	free(path);
	return (0);
}
