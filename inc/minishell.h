/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-nm <maria-nm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:11:28 by maria-nm          #+#    #+#             */
/*   Updated: 2024/07/05 19:48:41 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <term.h>
# include <curses.h>
# include <stdlib.h>

# include <readline.h>
# include <history.h>
# include "ft_printf.h"
# include "libft.h"
# include "ft_error.h"

//extern int exit_s; //declaracion variable global

# define READ    0    /* index pipe extremo lectura */
# define WRITE   1    /* index pipe extremo escritura */
# define PIPEX_INPUT 0 /* to define if it is firts or last pipe file*/
# define PIPEX_OUTPUT 1

// Signals
# define CTRL_C SIGINT
# define CTRL_D 4
# define CTRL_SLASH SIGQUIT

// Mode signals
# define PARENT 0
# define CHILDS 1

// ASCII characters
# define C_VERTICAL_BAR 124
# define C_LESS 60
# define C_GREAT 62
# define C_DOLLAR 36
# define C_ONE_QUOTE 39
# define C_TWO_QUOTE 34

// General errors
# define MSSG_INVALID_ARGS "Invalid arguments: Usage [./minishell]\n"
# define MSSG_MEMORY_ERROR "Memory error, please free space and attempt again\n"
# define MSSG_EXECUTOR_ERROR "Error during command execution\n"
# define MSSG_CMD_NOT_FOUND "command not found"
# define MSGG_NO_SUCH_FILE "No such file or directory"
# define MSGG_IS_A_DIR "is a directory"
# define MSSG_EXPORT_ERR "minishell: export: `%s': not a valid identifier\n"
# define MSSG_SHLVL_ERR "minishell: warning: shell level (%d) too high, \
resetting to 1\n"
# define MSSG_EXIT_NUM_ERR "minishell: exit: %s: numeric argument required\n"
# define MSSG_EXIT_ERR "minishell: exit: too many arguments\n"
# define MSSG_CD_ERR "minishell: cd: too many arguments\n"

// Parser syntax errors
# define SYNTAX_ERR 2
//# define SYNTAX_ERR 258
# define SYNTAX_NL 0
# define SYNTAX_PIPE 1
# define SYNTAX_LESS 6
# define SYNTAX_GREAT 3
# define SYNTAX_LESS_LESS 4
# define SYNTAX_GREAT_GREAT 5

typedef enum s_token
{
	NONE = 0,
	WHITE_SPACE,
	STRING,
	STRING_ONE_Q,
	STRING_TWO_Q,
	PIPE,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS
}		t_token;

//IN = <, HERE_DOC = <<, OUT = >,OUT_APPEND = >> 
typedef enum s_type
{
	REDIRECT_NONE = 0,
	IN,
	HERE_DOC,
	OUT,
	OUT_APPEND,
}		t_type;

/******************************************************************************/
/**
   @file  minishell.h
   @struct t_lex holds information for each token the lexical analyser finds.
           it is a node for a double linked list. 

   @var   word: the text that defines the token.
   @var  token: type of token. defined after analising the word.
   @var   prev: pointer to the next node in the list.
   @var	  next: pointer to the previous node in the list.

   USED ONLY WHEN IT IS A REDIRECTION LIST.
   @var   path: path to the filename mentioned in word.
   @var	  free: flag If 1 frees a strjoined word (not starting by '/').
   @var     fd: File descriptor for the file when it is openened.
   @var   is_w: flag settled when file is writable for current user.
   @var   is_r: flag settled when file is readable for current user.
   @var f_size: File size to control bigfiles tha block pipes.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/

/******************************************************************************/

typedef struct s_lex
{
	char			*word;
	t_token			token;
	struct s_lex	*prev;
	struct s_lex	*next;
	char			*path;
	int				token_free;
	int				fd;
	int				here_pipe[2];
	int				is_w;
	int				is_r;
	int				is_exp;
	long long		f_size;
}		t_lex;

typedef struct s_env
{
	char	**env;
	char	**export;
}		t_env;

/******************************************************************************/
/**
   @file  minishell.h
   @struct s_redirec holds information for one redirection 

   @var  type: redirection type (NONE,IN, HERE_DOC,OUT, OUT_APPEND)
   @var  file: file name written by user in the command line "infile.txt"
   @var  path: ABSOLUTE PATH to the file "/users/luis/docs/infile.txt"
   @var	   fd: file descriptor retuned by an open().
   @var  is_r: flag settled when file is readable for current user.
   @var  is_x: flag settled when file is executable for current user.
   @var	 free: flag If 1 frees a strjoined infile (not starting by '/').

   @details
   A pipex argument like "ls -al" will be separated in two parts, the command
   "ls" and the flags " -al". please notice the whitspace.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/

/******************************************************************************/
/**
   @file  minishell.h
   @struct s_ecmd holds command line command passsed 

   @var  cli: command line argument "wc" only.
   @var  cmd: command name wiht absolute path. "/usr/bin/wc".
   @var  flg: **char ready to pass it to execve "/usr/bin/wc" "-l" "NULL".
   @var	 pid: fork() returns it to the father each child borns.
   @vat free: flag If 1 frees a strjoined infile (not starting by '/').
   @var is_r: flag settled when command file is readable.
   @var is_x: flag settled when command file is executable.
   @var exit_status: keeps the cmd's exit status.
   @var redirect: a list with all redirection the command has (>,<, >>, <<).
   @var   ll: points to the last least ('<') redirection in redirect. 
   @var   lg: points to the last great ('>' or '>>') redirection out redirect.
   @var  lhd: points to the last less less ('<<').
   @var fd_ll: File descriptor of the last input redirection.
   @var fd_lg: File descriptor of the last outpur redirection.
   @var pipe: Holds the command's pipe.

   @details
   A pipex argument like "ls -al" will be separated in two parts, the command
   "ls" and the flags " -al". please notice the whitspace.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
typedef struct s_ecmd
{
	char	*cmd;
	char	*cli;
	char	**flg;
	pid_t	pid;
	int		cmd_free;
	int		is_r;
	int		is_x;
	int		is_d;
	int		is_exp_one;
	int		exit_status;
	t_lex	*redirect;
	t_lex	*ll;
	t_lex	*lg;
	int		fd_ll;
	int		fd_lg;
	int		pipe[2];
}	t_ecmd;
/******************************************************************************/
/**
   @file minishell.h
   @struct s_exec holds absolute paths to files and command used 

   @var  max_cmds: number of commands in readline
   @var  num_cmds: number of commands with verified absolute paths.
   @var	 exe_cmds: number of executed commands
   @var    all_ok: indicates if all files and commands are ok = 1.
   @var      path: Holds PATH enviromental var 
   @var       pwd: Holdes PWD enviromental var
   @var  one_pipe: The only one pipe that executor manages.
   @var  error_code :holds the error code returned by last command
   @var    **cmds: array of structures holding commands variables


   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
typedef struct s_exec
{
	int		max_cmds;
	int		num_cmds;
	int		exe_cmds;
	short	all_ok;
	char	*path;
	char	*pwd;
	int		fd_i;
	int		fd_o;
	char	*oldpwd;
	int		error_code;
	t_ecmd	**cmds;
}	t_exec;

//main.c		norminette
int				main(int ac, char **av, char **envp);
int				exit_status(int flag, int num);
char			*set_my_home(int flag, char **env);

//init.c		norminette-ok
t_env			*init_enve(char **env);
void			init_terminal(t_env *env);
//char			*generate_terminal(t_env *env);
char			*generate_terminal(void);
int				str_to_cmd(char *str, t_exec *inter, t_env *env);

//utils.c		norminette-ok
int				array_len(char **arr);
char			*ft_strdup_export(char *envp);
//void			print_matrix(char **matrix, int i);
void			ft_print_matrix(char **matrix, int i);
char			*find_home(char **env);
int				ft_strcmp(const char *s1, const char *s2);

//free.c		norminette-ok
char			**free_matrix(char **matrix, int j);
void			ft_matrix_free(char **matrix);
void			free_env(t_env *enve);

//signals.c		norminette-faltan comentarios
int				check_signals(int signum);
int				init_signals(int mode);

//utils2.c		norminette-ok
int				ft_isspace(int c);
int				ft_isquote(int c);
int				ft_is_one_quote(int c);
int				ft_is_two_quote(int c);
int				ft_isreserved(int c);

//utils3.c		norminette-ok
int				look_next_quote(char *str, int i);
int				ft_strlen_chr(char *str, char c);
int				ft_numlen(int n);
int				size_var(char *str);
int				token_is_any_string(t_token token);

//utils4.c		norminette-ok
char			*obtain_var(char *str);
int				ft_omit_var(char *var);
char			*expand(char *str, char **env);
int				calc_len_value_exp(char *str, char **env, int *len);
int				calc_len_exp(t_lex *lexer, char **env);

//utils_lists.c norminette-ok
t_lex			*lex_lstnew(void);
void			lex_lstadd_back(t_lex **lst, t_lex *new);
void			lex_lstclear(t_lex **lst);
int				lex_lstsize(t_lex *lst);
t_lex			*lex_lstlast(t_lex *lst);

//utils_lists2.c norminette-ok
void			lex_print_lst(t_lex *lst);
void			delete_white_space(t_lex **lexer);

//utils_lists3.c	norminette-ok
t_lex			*make_sublist(t_ecmd *cmd, t_lex *node, t_lex **list);

//utils_lists4.c	norminette-ok
t_lex			*remove_node(t_lex *current, t_lex **list);

//tokenizer.c	norminette-ok
int				tokenizer(char *str, t_lex **lex);

//tokenizer_utils.c norminette-ok
int				make_word(char *str, int i, t_lex *new);

//expansor.c	norminette-ok
void			expand_var(char *word, char *value, char *str, int len);
char			*create_value(char *word, int i, char **env);
void			change_token(t_lex *lexer, char *str);
int				expansor(t_lex **lexer, char **env);

//expansor_here.c norminette ok
char			*expansor_here(char *line, char **env);
void			make_expansion_here(char *line, char **env, char *str);
int				check_expansor_here(char *lexer);

//expansor_here2.c norminette ok
int				calc_len_value_exp_here(char *str, char **env, int *len);
int				calc_len_exp_here(char *str, char **env);

//expansor_utils.c norminette-ok
void			make_expansion(t_lex *lexer, char **env, char *str);

//parser.c		norminette-ok
int				parser(t_exec *inter, t_lex **lexer);
int				make_redirect(t_exec *inter, t_lex **lexer);

//parser_utils.c norminette-ok
int				ft_array_len(char **arr);
void			ft_free_array(char **arr, int i);
int				count_cmd(t_lex **lexer);
int				count_arg(t_lex *lexer);

//parser_utils2.c	norminette-ok
t_lex			*make_flg(t_ecmd *cmd, t_lex *lexer, int arg, t_lex **list);
int				make_exec(t_exec *inter, t_lex **lexer);

//utils_checks.c norminette-ok
int				check_expansor(t_lex *lexer);
int				check_dollar(char *word, int i);
int				check_tilde(char *w, int i);
char			*make_new_word(t_lex *tmp, t_lex *tmp_next);
int				check_cmd(char *command);

//utils_checks2.c norminette-ok
int				check_list(t_lex **lexer);

//utils_ckecks3.c norminette-ok
int				check_str_list(t_lex *tmp);
void			change_new_node(t_lex *n, char *new_word, t_lex *tmp);
void			free_tmp(t_lex *tmp);
void			update_list_links(t_lex *new_node, t_lex *tmp, t_lex **lexer);

//parser_lexic.c norminette-ok
int				check_syntax_error(t_lex *lexer);
int				check_pipe_error(t_lex *lexer);
int				check_duplicate_tokens(t_lex *lexer);
void			parser_error(int error);

//utils_env.c	norminette-ok
t_env			*dup_matrix_env(char **envp);
char			*arg_fin_env_var(char **env, char *var);
char			*arg_val_var(char *var);
char			**ft_add_env(char *str, char **env);
int				ft_strcmp_env(char *env, char *str);

//utils_export.c norminette-ok
char			*ft_strdup_join(char *str);
char			*ft_strjoin_export(char *s1, char *s2);
char			*ft_strjoin_env(char *s1, char *s2);
char			**ft_join_env(char *str, char **env);
char			**ft_join_export(char *str, char **export);

//utils_export2.c norminette-ok
void			ft_print_export(char **matrix);
int				check_format_export(char *str);
char			**ft_add_export(char *str, char **export);

//utils_file.c

/* ************************************************************************** */
/* arg_ok() checks arguments sent to pipex                                    */
/* ************************************************************************** */
void			arg_ok(t_exec *pip_arg);
/* ************************************************************************** */
/* arg_is_file() checks file arguments sent to pipex                          */
/* ************************************************************************** */
void			arg_is_file(t_lex *redir, t_exec *pip_arg);
/* ************************************************************************** */
/* arg_ok() checks argument sent to pipex                                     */
/* ************************************************************************** */

//utils_file2.c
/* ************************************************************************** */
/* open_file_properly() returns fd for a path file opened accordingly to token*/
/* ************************************************************************** */
int				open_file_properly(t_lex *redir, t_token token, char **env);

//utils_file3.c
/* ************************************************************************** */
/* open_have_access() checks for path available permissions                   */
/* ************************************************************************** */
int				have_access(const char *path, int mode);
/* ************************************************************************** */
/* open_is_directory() checks if path is a directory                          */
/* ************************************************************************** */
int				is_directory(const char *path);
/* ************************************************************************** */
/* open_pipes() open pipe and checks for open error                           */
/* ************************************************************************** */
int				open_pipes(t_exec *pinter, int *error);
void			close_exe_cmds_pipes(t_exec *a, const char *f, int l);
/* ************************************************************************** */
/* open_pipes_here() open_pipe for heredoc and checks for open error          */
/* ************************************************************************** */
int				open_pipes_here(t_lex *redir, int *error);

//executor.c
t_exec			fake_argument(void);
/// @brief 
/// @param inter 
/// @param environ 
/// @return 
//int				executor(t_exec inter, char **environ);
int				executor(t_exec inter, t_env **env);

//executor_close.c
void			my_close(int who, int *fd, const char *func, int line);

//int				cmd_n(t_exec a, char **env);
//executor_command.c
void			execute_one_command(t_exec a, t_env **env);

//executor_father.c 
//int				minis_execute_two(t_exec args, t_env **env);
//int				minis_execute_one(t_exec args, t_env **env);

//ecmd_struct.c
/* ************************************************************************** */
/* cmd_create() initializes a t_ecmd structure.                               */
/* ************************************************************************** */
t_ecmd			*ecmd_create(void);
/* ************************************************************************** */
/* cmd_destroy() frees memory used by a t_ecmd structure.                     */
/* ************************************************************************** */
void			ecmd_destroy(t_ecmd *cmd);
/* ************************************************************************** */
/* cmd_set_acc() set access permision for the commnad   .                     */
/* ************************************************************************** */
void			ecmd_set_acc(t_ecmd *a, int read, int exec);
/* ************************************************************************** */
/* cmd_set_dir_free() set if it is a directory or must be freed               */
/* ************************************************************************** */
void			ecmd_set_dir_free(t_ecmd *a, int dir, int free);

//executor_struct.c
/* ************************************************************************** */
/* exec_create() initializes a t_exec structure to hold max_cmds commands     */
/* ************************************************************************** */
t_exec			exec_create(int max_cmds);
/* ************************************************************************** */
/* exec_destroy() frees memory used by a t_exec structure.                    */
/* ************************************************************************** */
//void			exec_destroy(t_exec args);
void			exec_destroy(t_exec *args);

// show_t_exec.c
//show_t_exec(t_exec args);

//executor_utils.c
char			*arg_fin_com(char *com, t_exec *pip_arg);

// utils_redir.c
int				minis_execute_open_files(t_exec *inter, char **env);

// utils_redir2.c
void			duplicate_last_redirections(t_exec *pinter);
void			close_unused(t_exec *inter);
// utils_redir3.c
int				ret_perror(int e_num, char *msg1, char *msg2);
void			treat_last_redir(t_exec *pinter);
int				open_redirections(t_exec *inter, char **env);

//builtin_selector.c
int				builtin_selector(t_exec *pinter, t_env **env);

//builtin_cd.c	norminette	-ok
int				builtin_cd(char **args, char ***environ);

//builtin_echo.c	norminette-ok
int				builtin_echo(char **args);

//builtin_env.c	norminette-ok
int				builtin_env(char **env);

//builtin_exit.c	norminette-comentario
int				builtin_exit(char **args);

//builtin_export.c norminette-ok
int				builtin_export(char **args, t_env *env);
t_env			*ft_add_env_export(char *str, t_env *env);
t_env			*ft_join_env_export(char *str, t_env *env);
int				ft_strcmp_export(char *export, char *str);

//builtin_pwd.c	norminette-ok
int				builtin_pwd(void);

//builtin_unset.c	norminette-ok
int				builtin_unset(char **args, t_env *env);

//builtin_checker.c norminette -ok
int				builtin_exe(char *arg, char **args, t_env *env);
int				builtin_check(char *arg);
#endif
