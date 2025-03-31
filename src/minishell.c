/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:08:09 by lsellier          #+#    #+#             */
/*   Updated: 2025/03/31 22:40:50 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell(t_minishell *shell)
{
	char	*line;

	line = NULL;
	(void) shell;
	while (true)
	{
		signals(SIGNAL_EXECUTE);
		line = readline("\033[1;33mMini station essence ⛽ $ \033[0m");
		signals(SIGNAL_IGN);
		if (g_sig == 130)
			shell->exit_status = g_sig;
		if (line == NULL)
			return ;
		if (line[0] == '\0')
			continue ;
		if (line[0] == 't')
			shell->exit_status = 127;
		add_history(line);
	}
}
