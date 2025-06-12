/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:42:00 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/12 04:55:40 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../dprintf/ft_dprintf.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <dirent.h>
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
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# define MSG_PROMPT "Mini station essence $ "
# define MSG_PROMPT_COLOR "\033[1;33mMini station essence ⛽ $ \033[0m"
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
	char				*prompt;
	char				**env;
	char				*line;
	int					exit;
	int					exit_status;
	int					nb_args;
	int					nbr_file;
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
void					signals_wait(void);
char					**ft_tabdup(char **tab);
void					ft_free_tab(char **tab);
void					init_struct(t_minishell **shell, char **env, char *flag);
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
char					**expand_variable(char *str, t_minishell *shell);
int						redirection(t_minishell *shell, t_command *cmd);
void					delete_redirection(t_command *cmd, int *i);
char					*expand_in_quote(char *expanded_str, char *str, int *i,
							t_minishell *shell);
int						open_redirection_heredoc(t_minishell *shell,
							t_command *cmds, int i);
t_command				*ft_heredoc(t_minishell *shell);
char					*ft_expand_heredoc(t_minishell *shell, char *str);
// utils functions
int						ft_strcmp(const char *s1, const char *s2);
int						ft_isspace(int c);
int						est_dans_charset(char c);
int						ft_is_separator(char c);
int						ft_isspecial_char(char c, int flag);
char					*get_env_value(t_minishell *shell, char **env,
							char *str, int *i);
int						ft_is_quote(char c);
int						ft_tablen(char **tab);
void					skip_quotes(char *line, int *i, char quote);
int						count_tab_len(char *line);
int						have_lentabexpand(char *str, t_minishell *shell);
void					add_to_expanded_tab(t_minishell *shell, char *str,
							int *n[2], char **expanded_tab);
char					**get_env_value2(t_minishell *shell, char **env,
							char *str, int *i);
char					**edit_env_value(t_minishell *shell, char *value,
							char *new_one);
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
char					*ft_get_path(char *cmd, char **env);
void					ft_verif_is_directory(char **cmd_exec, char **env);
char					*my_getenv(char **env);
void					unlink_all_tmp(int nbr);
char					*have_tmp_file(int i);
void					ft_tabdel(char ***tab, char *value);
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
void					ft_wait_all_pid_without_last(t_minishell *shell);
int						ft_waitpid(t_minishell *shell, int or_and);
t_pid					*ft_add_pid(t_pid *pid_list, pid_t pid);
int						*have_static_int(int nbr);
void					ft_chose_next_separator(t_command *cmd,
							t_minishell *shell, int or_and);
void					ft_chose_next_separator_pipe(t_command *cmd,
							t_minishell *shell, int or_and);
void					ft_execute_lastcmd_pipe(t_command *cmd,
							t_minishell *shell);
// built-in functions
int						ft_echo(char **str, int flag);
int						pwd(t_minishell *shell);
int						ft_cd(t_minishell *minishell, char **cmd);
int						env(t_minishell *minishell);
int						ft_parse_echo(t_minishell *shell, t_command *cmd);
int						ft_parse_env(t_minishell *shell, t_command *cmd);
int						ft_parse_cd(t_minishell *shell, t_command *cmd);
int						ft_parse_exit(t_minishell *shell, t_command *cmd);
int						ft_parse_pwd(t_minishell *shell, t_command *cmd);
int						ft_parse_unset(t_minishell *shell, t_command *cmd);
int						ft_parse_export(t_minishell *shell, t_command *cmd);
int						ft_exit(t_minishell *shell, char **tab);
void					ft_unset(t_minishell *shell, char **unset);
int						ft_export(t_minishell *shell, char **export);
int						have_equal(char *str);
int						found_error(char *export, int j, t_minishell *shell);
char					*before_equal(char *value);
int						isinenv(t_minishell *shell, char *name, char *result);
#endif
