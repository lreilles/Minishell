/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:46:52 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/10 23:48:37 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_t_command(t_minishell *shell)
{
	t_command	*tmp;

	while (shell->cmds)
	{
		ft_free_tab(shell->cmds->cmd);
		tmp = shell->cmds->next;
		free(shell->cmds);
		shell->cmds = tmp;
	}
}
