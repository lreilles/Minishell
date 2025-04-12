/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:43:51 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/12 04:11:35 by lsellier         ###   ########.fr       */
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

static void	quit_handler(int sig)
{
	(void)sig;
	g_sig = 130;
	exit(130);
}

void	signals(int sig)
{
	if (sig == SIGNAL_EXECUTE)
	{
		sigaction(SIGINT, &(struct sigaction){.sa_handler = int_handler}, NULL);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGPIPE, SIG_IGN);
	}
	else if (sig == SIGNAL_HERE_DOC)
	{
		sigaction(SIGINT, &(struct sigaction){.sa_handler = quit_handler},
			NULL);
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
