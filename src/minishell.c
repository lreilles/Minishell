/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:08:09 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/10 09:08:30 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell(t_minishell *shell)
{
	while (true)
	{
		signals(SIGNAL_EXECUTE);
		shell->line = readline("\033[1;33mMini station essence "
				"⛽ $ \033[0m");
		signals(SIGNAL_IGN);
		if (g_sig == 130 || g_sig == 131)
		{
			shell->exit_status = g_sig;
			g_sig = 0;
		}
		if (shell->line == NULL)
			return ((void)ft_dprintf(2, "exit\n"));
		if (ft_strcmp(shell->line, "") == 0)
		{
			free(shell->line);
			continue ;
		}
		add_history(shell->line);
		if (parsing(shell, shell->line))
			ft_execute_cmds(shell);
		free(shell->line);
		shell->line = NULL;
	}
}
