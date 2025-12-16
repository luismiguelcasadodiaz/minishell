/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:26:10 by maria-nm          #+#    #+#             */
/*   Updated: 2024/07/02 16:23:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_error.h"

//flag == 0 read, flag == 1 Set
int	exit_status(int flag, int num)
{
	static int	exit_s;

	if (flag == 1)
		exit_s = num;
	return (exit_s);
}

char	*set_my_home(int flag, char **env)
{
	static char	*my_home;
	char		*aux;
	char		*aux2;
	int			num_slash;
	int			i;

	if (flag == 1)
	{
		aux = arg_fin_env_var(env, "PWD");
		aux2 = arg_val_var(aux);
		num_slash = 0;
		i = 0;
		while (aux2[i] && num_slash < 3)
		{
			if (aux2[i] == '/')
				num_slash++;
			i++;
		}
		my_home = ft_substr(aux2, 0, --i);
		free(aux2);
	}
	if (flag == -1)
		free(my_home);
	return (my_home);
}

static char	**make_fake_envp(void)
{
	char	**envp;
	char	*tmp;

	envp = (char **)malloc(5 * sizeof(char *));
	if (!envp)
	{
		ft_printf_fd(STDERR_FILENO, "malloc problems\n!");
		exit(1);
	}
	tmp = getcwd(NULL, 0);
	envp[0] = ft_strjoin("PWD=", tmp);
	envp[1] = ft_strjoin("SHLVL=", "1");
	envp[2] = ft_strjoin("_=", "/usr/bin/env");
	envp[3] = ft_strjoin("OLDPWD=", tmp);
	envp[4] = NULL;
	free (tmp);
	return (envp);
}

static void	free_fake_env(char **envp)
{
	free(envp[4]);
	free(envp[3]);
	free(envp[2]);
	free(envp[1]);
	free(envp[0]);
	free(envp);
}

int	main(int ac, char **av, char **envp)
{
	t_env	*enve;

	(void)av;
	exit_status(1, 0);
	if (ac != 1)
		return (ft_printf_fd(2, MSSG_INVALID_ARGS), 1);
	if (!envp[0])
	{
		envp = make_fake_envp();
		enve = dup_matrix_env(envp);
		free_fake_env(envp);
	}
	else
		enve = dup_matrix_env(envp);
	if (!enve)
		return (ft_printf_fd(2, MSSG_MEMORY_ERROR), 0);
	init_signals(PARENT);
	set_my_home(1, (*enve).env);
	init_terminal(enve);
	free_env(enve);
	set_my_home(-1, NULL);
	return (exit_status(0, 0));
}
