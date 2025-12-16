/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:48:23 by luicasad          #+#    #+#             */
/*   Updated: 2024/06/25 00:33:38 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include "ft_error.h"

static void	create_my_cmds(t_exec *r)
{
	int	i;

	r->cmds = (t_ecmd **) malloc(r->max_cmds * sizeof(t_ecmd *));
	if (!r->cmds)
	{
		ft_error_print(ERR005, __func__, __LINE__);
		exit(-1);
	}
	i = -1;
	while (++i < r->max_cmds)
		r->cmds[i] = ecmd_create();
}

/******************************************************************************/
/**
  @file executor_struct.c
  @brief exec_create() creates a structure to support n commands

  @param[in] max_cmds: the number of comnans included in the readline.

  @details:
  When max_cmds = 0 r.cmds = NULL is better than a Malloc(0); 

******************************************************************************/
t_exec	exec_create(int max_cmds)
{
	t_exec	r;

	r.max_cmds = max_cmds;
	r.num_cmds = 0;
	r.exe_cmds = 0;
	r.all_ok = 1;
	r.path = NULL;
	r.pwd = NULL;
	r.oldpwd = NULL;
	r.fd_i = -1;
	r.fd_o = -1;
	if (max_cmds != 0)
		create_my_cmds(&r);
	else
		r.cmds = NULL;
	r.error_code = 0;
	return (r);
}

/******************************************************************************/
/**
  @file executor_struct.c
  @brief exec_destroy() frees allocated memory in an ecmd strucut

  @param[in] cmd: string for cmd
  @param[in] flg:string for cmd's flags

  @details
  maybe the commnad has several flags, so i loop all flags o free the formerly
  splitted flags,
******************************************************************************/

void	exec_destroy(t_exec *args)
{
	int	i;

	if (!args)
		return ;
	i = args->max_cmds;
	while (--i >= 0)
	{
		if (args->cmds[i])
		{
			ecmd_destroy(args->cmds[i]);
			free(args->cmds[i]);
		}
	}
	free(args->cmds);
	free(args->path);
	free(args->pwd);
	free(args->oldpwd);
	args->cmds = NULL;
	args->path = NULL;
	args->pwd = NULL;
	args->oldpwd = NULL;
}
