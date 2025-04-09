/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:42:00 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/09 05:05:31 by lsellier         ###   ########.fr       */
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

extern int	g_sig;

typedef struct s_minishell
{
	char	**env;
	char	*line;
	int		exit_status;
	int		nb_args;
	char	**args;
}			t_minishell;

typedef struct s_command
{
	char	*cmd;
	char	**args;
}			t_command;

void		minishell(t_minishell *shell);
void		signals(int sig);
char		**ft_tabdup(char **tab);
void		ft_free_tab(char **tab);
void		init_struct(t_minishell **shell, char **env);
int			free_struct(t_minishell *shell);
void		close_fds(void);

// parsing functions
int			parsing(t_minishell *shell, char *line);
int			is_quote_closed(const char *line);
char		**ft_split_minishell(char *line);
int			verif_special_char(char **tab, t_minishell *shell);
int			verif_error(char **tab, t_minishell *shell, char *line);
// void	parsing_redir(t_minishell *shell, char *line);

// utils functions
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isspace(int c);
int			est_dans_charset(char c);
int			ft_is_separator(char c);
int			ft_is_quote(char c);
void		skip_quotes(char *line, int *i, char quote);
int			count_tab_len(char *line);
void		increment_if_necessary(int *len, int *add_len);
void		separator_count(char *line, int *i, int *len, int *add_len);
int			ft_isspecial(int i, char *str);
int			ft_issplit_cmd(char *str);
// executing functions
void		ft_execute_cmds(t_minishell *shell);
#endif
