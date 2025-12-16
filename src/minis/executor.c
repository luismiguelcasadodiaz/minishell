/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:57:30 by luicasad          #+#    #+#             */
/*   Updated: 2024/06/15 09:59:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_error.h"
#include <stdlib.h>

/******************************************************************************/
/**
   @file executor.c
   @brief arg_val_var() returns the text after '=' from an enviromental var

   @param[in]  *vars: an enviromental variable wiht this format:
            NAME=VALUE

   @details
   Set into interface strucutre PWD and PATH to use it in the command
   validation made by arg_ok.

   Executes the command

   Frees interface strucuture

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
int	executor(t_exec inter, t_env **env)
{
	int		error;
	char	*aux;

	inter.fd_i = dup(STDIN_FILENO);
	inter.fd_o = dup(STDOUT_FILENO);
	error = 0;
	init_signals(CHILDS);
	aux = arg_fin_env_var((*env)->env, "PATH");
	inter.path = arg_val_var(aux);
	aux = arg_fin_env_var((*env)->env, "PWD");
	inter.pwd = arg_val_var(aux);
	aux = NULL;
	arg_ok(&inter);
	if (inter.all_ok)
		error = builtin_selector(&inter, env);
	exec_destroy(&inter);
	dup2(inter.fd_i, STDIN_FILENO);
	my_close(-1, &inter.fd_i, __func__, __LINE__);
	dup2(inter.fd_o, STDOUT_FILENO);
	my_close(-1, &inter.fd_o, __func__, __LINE__);
	return (error);
}
