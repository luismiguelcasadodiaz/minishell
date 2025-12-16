/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:36:56 by maria-nm          #+#    #+#             */
/*   Updated: 2024/04/29 13:47:34 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	control_parent(int signum)
{
	if (signum == CTRL_C)
	{
		ft_printf("\n");
		exit_status(1, 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	control_child(int signum)
{
	if (signum == CTRL_C)
	{
		ft_printf("\n");
		exit_status(0, 0);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
	else if (signum == CTRL_SLASH)
		ft_printf("Quit: 3\n");
}

int	check_signals(int signum)
{
	if (signum == CTRL_C)
	{
		signal(CTRL_C, control_parent);
	}
	if (signum == CTRL_D)
		signal(CTRL_D, control_parent);
	signal(CTRL_SLASH, control_parent);
	return (1);
}

int	init_signals(int mode)
{
	struct termios	tc;

	if (mode == PARENT)
	{
		tcgetattr(0, &tc);
		tc.c_lflag &= ~ECHOCTL;
		signal(CTRL_C, control_parent);
		signal(CTRL_SLASH, SIG_IGN);
		tcsetattr(0, TCSANOW, &tc);
	}
	else if (mode == CHILDS)
	{
		signal(CTRL_C, control_child);
		signal(CTRL_SLASH, control_child);
		tcgetattr(0, &tc);
		tc.c_lflag |= ECHOCTL;
		tcsetattr(0, TCSANOW, &tc);
	}
	return (1);
}
