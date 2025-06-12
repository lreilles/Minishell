/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <ameduboi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 07:56:55 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/12 03:19:26 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_parse_export(t_minishell *shell, t_command *cmd)
{
	int	tmp[2];

	redirection(shell, cmd);
	tmp[0] = dup(0);
	tmp[1] = dup(1);
	if (ft_dup2(cmd))
		return (1);
	new_cmd_expand(&cmd->cmd, shell);
	shell->exit_status = 0;
	shell->exit_status = ft_export(shell, cmd->cmd + 1);
	dup2(tmp[0], 0);
	dup2(tmp[1], 1);
	return (shell->exit_status);
}
