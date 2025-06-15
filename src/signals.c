/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:43:51 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/15 16:10:09 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			g_sig = 0;

static void	int_handler(int sig)
{
	(void)sig;
	ft_dprintf(2, "\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_sig = 130;
}

static void	here_doc_sigint(int sig)
{
	(void)sig;
	ft_dprintf(2, "\n");
	g_sig = 130;
	close(0);
	close(1);
	close(2);
}

void	signals(int sig)
{
	if (sig == SIGNAL_EXECUTE)
	{
		signal(SIGINT, int_handler);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGPIPE, SIG_IGN);
	}
	else if (sig == SIGNAL_HERE_DOC)
	{
		signal(SIGINT, here_doc_sigint);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGPIPE, SIG_IGN);
	}
	else if (sig == SIGNAL_DEFAULT)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		signal(SIGPIPE, SIG_DFL);
	}
	else if (sig == SIGNAL_IGN)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGPIPE, SIG_IGN);
	}
}
