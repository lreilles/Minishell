/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:42:00 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/06 01:12:14 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../dprintf/ft_dprintf.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# ifndef SIGNALS
#  define SIGNALS
#  define SIGNAL_EXECUTE 1
#  define SIGNAL_IGN 2
#  define SIGNAL_DEFAULT 3
#  define SIGNAL_HERE_DOC 4
# endif

extern int				g_sig;

typedef struct s_minishell
{
	char				**env;
	char				*line;
	int					exit_status;
	int					nb_args;
	char				**args;
	struct s_pid		*pid_list;
	struct s_command	*cmds;

}						t_minishell;

typedef struct s_pid
{
	pid_t				pid;
	struct s_pid		*next;
}						t_pid;

typedef struct s_command
{
	struct s_command	*next;
	char				**cmd;
	int					fd_in_put;
	int					fd_out_put;
	pid_t				pid;
}						t_command;

void					minishell(t_minishell *shell);
void					signals(int sig);
char					**ft_tabdup(char **tab);
void					ft_free_tab(char **tab);
void					init_struct(t_minishell **shell, char **env);
int						free_struct(t_minishell *shell);
void					close_fds(int fd);
void					close_fds_without(int fd, int fd_in, int fd_out);

// parsing functions
int						parsing(t_minishell *shell, char *line);
int						is_quote_closed(const char *line);
char					**ft_split_minishell(char *line);
int						verif_special_char(char **tab, t_minishell *shell);
int						verif_error(char **tab, t_minishell *shell, char *line);
t_command				*creat_cmds(t_minishell *shell);
char					*expand_variable(char *str, char **env,
							t_minishell *shell);
char					**expand_variable2(char *str, t_minishell *shell);
int						redirection(t_minishell *shell, t_command *cmd);
void					delete_redirection(t_command *cmd, int *i);
char					*expand_in_quote(char *expanded_str, char *str, int *i,
							t_minishell *shell);
// utils functions
int						ft_strcmp(const char *s1, const char *s2);
int						ft_isspace(int c);
int						est_dans_charset(char c);
int						ft_is_separator(char c);
char					*get_env_value(t_minishell *shell, char **env,
							char *str, int *i);
int						ft_is_quote(char c);
int						ft_tablen(char **tab);
void					skip_quotes(char *line, int *i, char quote);
int						count_tab_len(char *line);
void					increment_if_necessary(int *len, int *add_len);
void					separator_count(char *line, int *i, int *len,
							int *add_len);
int						acess_file(t_minishell *shell, char *file, int flags);
char					*without_quotes(char *str);
char					*ft_strjoin_char(char *str, char c);
int						ft_isspecial(int i, char *str);
int						ft_issplit_cmd(char *str);
void					ft_free_t_command(t_minishell *shell);
int						ft_counts_cmds(t_command *cmd);
void					skip_expand_null(char **cmd, t_minishell *shell,
							int *i);
void					ft_free_t_pid(t_pid *pid_list);
int						ft_dup2(t_command *cmd);
void					ft_free_before_exit(t_minishell *shell, int fd_in,
							int fd_out);
char					*ft_strjoin_check(char *str1, char *str2);
// executing functions
void					ft_execute_cmds(t_minishell *shell);
void					ft_execute_lastcmd(t_command *cmd, t_minishell *shell,
							int or_and);
void					ft_execute_pipe(t_command *cmd, t_minishell *shell,
							int or_and);
void					ft_execute_or(t_command *cmd, t_minishell *shell,
							int or_and, int ispipe);
void					ft_execute_and(t_command *cmd, t_minishell *shell,
							int or_and, int ispipe);
void					ft_execute_cmd(t_command *cmd, t_minishell *shell);
void					ft_execute_builtin(t_minishell *shell, t_command *cmd);
int						ft_isbuiltin(t_command *cmd, t_minishell *shell);
void					ft_execute_builtin_pipe(t_minishell *shell,
							t_command *cmd);
void					new_cmd_expand(char ***cmd, t_minishell *shell);
void					ft_execute_with_fork(t_command *cmd,
							t_minishell *shell);
void					ft_wait_pid_exit_status(t_minishell *shell);
// built-in functions
void					ft_echo(char **str, int flag);
int						ft_parse_echo(t_minishell *shell, t_command *cmd);
void					env(char **env);
int						ft_parse_env(t_minishell *shell, t_command *cmd);
#endif
