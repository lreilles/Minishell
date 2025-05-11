/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:59:54 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/11 04:07:28 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	open_redirection_heredoc(t_minishell *shell, t_command *cmds, int i)
{
	cmds->fd_in_put = open(cmds->cmd[i + 1], O_RDONLY);
	if (cmds->fd_in_put == -1)
	{
		ft_dprintf(2, "minishell: %s: No such file or directory\n",
			cmds->cmd[i + 1]);
		shell->exit_status = 1;
		return (1);
	}
	return (0);
}
