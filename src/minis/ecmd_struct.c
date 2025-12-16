/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecmd_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:32:50 by luicasad          #+#    #+#             */
/*   Updated: 2024/06/28 16:36:32 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include "ft_error.h"
#include <stdio.h>
/******************************************************************************/
/**
  @file cmd_struct.c
  @brief ecmd_create() creates a structure to hold a command line command

  @details
  At this point read and execute right are not tested so flags ar KO
******************************************************************************/
static void	ecmd_set_pointers_to_null(t_ecmd **r)
{
	(*r)->cmd = NULL;
	(*r)->cli = NULL;
	(*r)->flg = NULL;
	(*r)->redirect = NULL;
	(*r)->ll = NULL;
	(*r)->lg = NULL;
}

t_ecmd	*ecmd_create(void)
{
	t_ecmd	*r;

	r = (t_ecmd *) malloc(sizeof(t_ecmd));
	if (!r)
	{
		ft_error_print(ERR005, __func__, __LINE__);
		exit(-1);
	}
	ecmd_set_pointers_to_null(&r);
	r->pid = -1;
	r->cmd_free = 0;
	r->is_r = 0;
	r->is_x = 0;
	r->is_d = 0;
	r->is_exp_one = 0;
	r->exit_status = 0;
	r->fd_lg = -1;
	r->fd_ll = -1;
	r->pipe[READ] = -1;
	r->pipe[WRITE] = -1;
	return (r);
}

/******************************************************************************/
/**
  @file cmd_struct.c
  @brief ecmd_destroy() frees allocated memory in an ecmd strucut

  @param[in] cmd: string for cmd
  @param[in] flg:string for cmd's flags

  @details
  maybe the commnad has several flags, so i loop all flags o free the formerly
  splitted flags,
  redirect list may has absoluted paths thae were strjoined, so require free
******************************************************************************/
void	ecmd_destroy(t_ecmd *x)
{
	int		i;
	t_lex	*redir;
	t_lex	*to_free;

	redir = x->redirect;
	while (redir)
	{
		if (token_is_any_string(redir->token))
			free(redir->word);
		if (redir->token_free)
			free(redir->path);
		to_free = redir;
		redir = redir->next;
		free(to_free);
	}
	lex_lstclear(&redir);
	i = 0;
	while (x->flg[i] != NULL)
		free(x->flg[i++]);
	free(x->flg);
	if (x->cmd_free)
		free(x->cmd);
	ecmd_set_pointers_to_null(&x);
	x = NULL;
}

// Set command read/execute 
void	ecmd_set_acc(t_ecmd *a, int read, int exec)
{
	a->is_r = read;
	a->is_x = exec;
}

void	ecmd_set_dir_free(t_ecmd *a, int dir, int free)
{
	a->is_d = dir;
	a->cmd_free = free;
}
