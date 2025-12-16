/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:49:14 by maria-nm          #+#    #+#             */
/*   Updated: 2024/06/30 23:54:13 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_error.h"
#include <sys/stat.h>

void	arg_is_file(t_lex *redir, t_exec *pip_arg)
{
	char	*slash_file;

	if (token_is_any_string(redir->token))
	{
		redir->path = NULL;
		if (pip_arg->pwd)
		{
			if (redir->word[0] != '/')
			{
				slash_file = ft_strjoin("/", redir->word);
				redir->path = ft_strjoin(pip_arg->pwd, slash_file);
				free(slash_file);
				redir->token_free = 1;
			}
			else
				redir->path = redir->word;
		}
	}
}

/******************************************************************************/
/**
   @file utils_env.c
   @brief arg_is_command() finds if command comes in any of PATH's paths is 
   executable. If it is, returns full path, otherwise NULL

   @param[in]  arg: the pipex argument to verify if its command is executable.
   @param[out] pip_arg : the pipex structur to keep the executable command wiht
   	the flags

   @returns
   The all_ok flag of the Pipex structure that reports if till now pipex will
   be able to execute the arguments.

   @details
   Find the PATH in the enviroment and gets its value.
   Sets the command inside the pipex structure.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
void	arg_is_command(char *arg, t_exec *pip_arg)
{
	char	*arg_cmd;
	char	**arg_flags;

	arg_flags = ft_split_pipex(arg, ' ');
	arg_cmd = arg_fin_com(arg_flags[0], pip_arg);
	if (pip_arg->num_cmds < pip_arg->max_cmds)
	{
		pip_arg->cmds[pip_arg->num_cmds]->cmd = arg_cmd;
		pip_arg->cmds[pip_arg->num_cmds]->cli = arg_flags[0];
		pip_arg->cmds[pip_arg->num_cmds++]->flg = arg_flags;
		pip_arg->all_ok = (pip_arg->all_ok && \
							pip_arg->cmds[pip_arg->num_cmds]->is_r && \
							pip_arg->cmds[pip_arg->num_cmds]->is_x);
	}
	else
		ft_error_print(ERR050, __func__, __LINE__);
}

/******************************************************************************/
/**
   @file utils_env.c
   @brief arg_ok() checks if pipex arguments are accesible or executable.

   @param[in] argc: number of arguments to verify.
   @param[in] argv: table  of arguments to verify.
   @param[in] environ: environment to find PAHT and PWD variables.
   @param[in] pip_arg: struct that keep checking result.

   @details
   Set the hypothesis all arguments are ok (all_ok = 1) at creation time.
   Locates PWD and PATH enviromen variables.
   Checks input file
   Checks commands
   Checks output file
   set all_ok that reports with 1 that all arguments are accesible or
     ejecutable- Otherwise retunrs 0.

******************************************************************************/
static void	check_cmds(t_exec *p)
{
	int	i;

	i = -1;
	while (++i < p->max_cmds)
	{
		p->num_cmds = i;
		p->cmds[i]->cmd = arg_fin_com(p->cmds[i]->flg[0], p);
		p->cmds[i]->cli = p->cmds[i]->flg[0];
	}
}

static void	check_redirs(t_exec *p)
{
	int		i;
	t_lex	*this_redir;

	i = -1;
	while (++i < p->max_cmds)
	{
		this_redir = p->cmds[i]->redirect;
		while (this_redir)
		{
			arg_is_file(this_redir, p);
			this_redir = this_redir->next;
		}
	}
}

void	arg_ok(t_exec *p)
{
	if (p->pwd)
	{
		check_cmds(p);
		check_redirs(p);
	}
	else
		if (!builtin_check(p->cmds[0]->flg[0]))
			p->all_ok = 0;
}
