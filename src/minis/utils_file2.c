/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:05:18 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/01 01:08:07 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static long long	get_file_size(char *path, long long *size)
{
	struct stat	file_info;
	int			error;

	if (stat(path, &file_info) == -1)
	{
		error = errno;
		ft_error_print(error, __func__, __LINE__);
		return (1);
	}
	*size = file_info.st_size;
	return (0);
}

static char	*treat_here_line(char *line, t_lex *redir, char **env)
{
	char	*result;
	char	*line_exp;

	if (!line)
		return (NULL);
	if (redir->token == STRING && check_expansor_here(line) >= 0)
	{
		line_exp = expansor_here(line, env);
		result = ft_strjoin(line_exp, "\n");
		free(line_exp);
	}
	else
	{
		result = ft_strjoin(line, "\n");
		free(line);
	}
	return (result);
}

static void	read_heredoc(int tag_len, t_lex *redir, char **env)
{
	int		line_len_lf;
	char	*line_lf;

	while (1)
	{
		line_lf = treat_here_line(readline("> "), redir, env);
		if (!line_lf)
			return (my_perror("warning: here-document delimited by end-of-file,\
			 but expecting ", redir->word));
		line_len_lf = ft_strlen(line_lf);
		if (!ft_strncmp(line_lf, redir->word, tag_len))
		{
			free(line_lf);
			my_close(0, &redir->here_pipe[WRITE], __func__, __LINE__);
			break ;
		}
		write (redir->here_pipe[WRITE], line_lf, line_len_lf);
		free(line_lf);
	}
}

static int	open_less_less(t_lex *redir, char **env)
{
	int		error;
	int		tag_len;

	if (open_pipes_here(redir, &error))
		return (exit_status(1, error));
	tag_len = ft_strlen(redir->word);
	read_heredoc(tag_len, redir, env);
	return (0);
}

int	open_file_properly(t_lex *redir, t_token token, char **env)
{
	if (token == LESS)
	{
		redir->fd = open(redir->path, O_RDONLY);
		if (redir->fd != -1)
			get_file_size(redir->path, &redir->f_size);
	}
	if (token == LESS_LESS)
		open_less_less(redir, env);
	if (token == GREAT)
		redir->fd = open(redir->path, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (token == GREAT_GREAT)
		redir->fd = open(redir->path, O_WRONLY | O_APPEND | O_CREAT, 0664);
	if (redir->fd == -1 && redir->here_pipe[READ] == -1)
	{
		my_perror(redir->word, NULL);
		return (1);
	}
	else
		return (0);
}
