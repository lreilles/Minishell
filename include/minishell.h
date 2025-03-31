/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:42:00 by lsellier          #+#    #+#             */
/*   Updated: 2025/03/31 22:37:09 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../dprintf/ft_dprintf.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
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
	int		exit_status;
}			t_minishell;

void	minishell(t_minishell *shell);
void	signals(int sig);
#endif
