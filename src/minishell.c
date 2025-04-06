/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:08:09 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/01 22:29:05 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell(t_minishell *shell)
{
	char	*line;

	line = NULL;
	while (true)
	{
		signals(SIGNAL_EXECUTE);
		line = readline("\033[1;33mMini station essence ⛽ $ \033[0m");
		signals(SIGNAL_IGN);
		if (g_sig == 130)
		{
			shell->exit_status = g_sig;
			g_sig = 0;
		}
		if (line == NULL)
			return ;
		if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		add_history(line);
		parsing(shell, line);
		free(line);
	}
}
