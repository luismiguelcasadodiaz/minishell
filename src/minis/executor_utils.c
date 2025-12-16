/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:00:28 by luicasad          #+#    #+#             */
/*   Updated: 2024/06/24 23:54:42 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// joins to one path the command and checks access
static void	test_path(t_exec *p, \
				char *path, \
				char *slash_c, \
				char **result)
{
	char	*command;

	if (!(*result))
	{
		command = ft_strjoin(path, slash_c);
		if (have_access(command, R_OK))
		{
			*result = command;
			ecmd_set_acc(p->cmds[p->num_cmds], 1, have_access(command, X_OK));
			ecmd_set_dir_free(p->cmds[p->num_cmds], is_directory(command), 1);
		}
		else
			free(command);
	}
}

/******************************************************************************/
/**
   @file arg_fin_com.c
   @brief arg_fin_com() finds if command com in any of PATH's paths is 
   executable. If it is, returns full path, oterhmise NULL

   @param[in]  var_val: holds the content of PATH variable after '='
   @param[in]      com: the command to locate

   @details
   Splits var_val by ':'. 
   Joins to each path the command and test if can access the composition.
   if command is accesible and executable save it as result.
   Frees each invalid path.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
static char	**get_paths(char *path_val)
{
	char	**paths;

	paths = ft_split(path_val, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

// result argument is passed with as NULL value.
// test_path() changess it when finds a readabla path.
// despite finding a readabel path, the function loops all paths to free them
static void	my_help(char *com, t_exec *p, char **result, char *path_val)
{
	char	**paths;
	char	*slash_command;
	int		len;

	slash_command = ft_strjoin("/", com);
	len = 0;
	paths = get_paths(path_val);
	if (paths != NULL)
	{
		while (paths[len] != NULL)
		{
			test_path(p, paths[len], slash_command, result);
			free(paths[len]);
			len++;
		}
	}
	else
	{
		ecmd_set_acc(p->cmds[p->num_cmds], 0, 0);
		ecmd_set_dir_free(p->cmds[p->num_cmds], 0, 0);
	}
	free(slash_command);
	free(paths);
}

// checks commands starting by './' in PWD
char	*arg_find_point_slash(char *com, t_exec *p)
{
	char	*result;
	char	*path_val;
	char	*slash_command;
	char	*command;
	t_ecmd	*c;

	result = NULL;
	path_val = p->pwd;
	if (path_val)
	{
		c = p->cmds[p->exe_cmds];
		slash_command = ft_strjoin("/", com);
		command = ft_strjoin(path_val, slash_command);
		ecmd_set_acc(c, have_access(com, R_OK), \
						have_access(com, X_OK));
		ecmd_set_dir_free(c, is_directory(command), 1);
		result = command;
		free(slash_command);
	}
	else
		ft_error_print(ERR006, __func__, __LINE__);
	return (result);
}

// checks commands starting by any character in PATH 
/*static char	*find_file_in_path(char *com, t_exec *p)
{
	char	*result;
	char	*path_val;

	result = NULL;
	path_val = arg_val_var(p->path);
	if (path_val)
		my_help(com, p, &result, path_val);
	else
		ft_error_print(ERR006, __func__, __LINE__);
	return (result);
}
*/
char	*arg_fin_com(char *com, t_exec *p)
{
	char	*result;

	if (!com)
		return (NULL);
	result = NULL;
	if (com[0] == '.')
		result = arg_find_point_slash(com, p);
	else if (com[0] == '/')
	{
		ecmd_set_acc(p->cmds[p->num_cmds], have_access(com, R_OK), \
		have_access(com, X_OK));
		ecmd_set_dir_free(p->cmds[p->num_cmds], is_directory(com), 0);
		if (p->cmds[p->num_cmds]->is_r)
			result = com;
		else
			result = NULL;
	}
	else
		my_help(com, p, &result, p->path);
	return (result);
}
