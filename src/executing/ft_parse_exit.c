/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 08:17:27 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/09 04:50:11 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_parse_exit(t_minishell *shell, t_command *cmd)
{
	int	tmp[2];

	redirection(shell, cmd);
	tmp[0] = 0;
	tmp[1] = 1;
	if (ft_dup2(cmd))
		return (1);
	new_cmd_expand(&cmd->cmd, shell);
	if (cmd->cmd[1])
		shell->exit_status = ft_atoi(cmd->cmd[1]);
	shell->exit = 1;
	// ft_exit(shell, cmd->cmd + 1);
	dup2(tmp[0], 0);
	dup2(tmp[1], 1);
	return (shell->exit_status);
}
