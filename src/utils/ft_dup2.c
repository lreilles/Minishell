/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:17:52 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/14 02:15:49 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_dup2(t_minishell *shell, t_command *cmd)
{
	if (cmd->fd_in_put != 0)
	{
		if (dup2(cmd->fd_in_put, 0) == -1)
			return (close_fds(&shell->fd_list), ft_dprintf(2,
					"minishell: dup2 failed\n"), 1);
		close(cmd->fd_in_put);
	}
	if (cmd->fd_out_put != 1)
	{
		if (dup2(cmd->fd_out_put, 1) == -1)
			return (close_fds(&shell->fd_list), ft_dprintf(2,
					"minishell: dup2 failed\n"), 1);
		close(cmd->fd_out_put);
	}
	return (0);
}
