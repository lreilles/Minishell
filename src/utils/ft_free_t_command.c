/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:46:52 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/28 06:19:33 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_t_command(t_minishell *shell)
{
	t_command	*tmp;
	t_pid		*tmp_pid;

	while (shell->cmds)
	{
		ft_free_tab(shell->cmds->cmd);
		tmp = shell->cmds->next;
		free(shell->cmds);
		shell->cmds = tmp;
	}
	while (shell->pid_list)
	{
		tmp_pid = shell->pid_list;
		shell->pid_list = shell->pid_list->next;
		free(tmp_pid);
	}
	shell->pid_list = NULL;
}
