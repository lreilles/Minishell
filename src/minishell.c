/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:08:09 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/28 06:30:05 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell(t_minishell *shell)
{
	while (true)
	{
		signals(SIGNAL_EXECUTE);
		shell->line = readline("\033[1;33mMini station essence ⛽ $ \033[0m");
		signals(SIGNAL_IGN);
		if (g_sig == 130)
		{
			shell->exit_status = g_sig;
			g_sig = 0;
		}
		if (shell->line == NULL)
			return ((void)ft_dprintf(2, "exit\n"));
		if (shell->line[0] == '\0')
		{
			free(shell->line);
			continue ;
		}
		add_history(shell->line);
		if (parsing(shell, shell->line))
			ft_execute_cmds(shell);
		free(shell->line);
	}
}
