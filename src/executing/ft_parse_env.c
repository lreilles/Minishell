/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:51:37 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/14 01:23:22 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_parse_env(t_minishell *shell, t_command *cmd)
{
	int	tmp[2];

	redirection(shell, cmd);
	tmp[0] = dup(0);
	tmp[1] = dup(1);
	shell->exit_status = 0;
	if (ft_dup2(cmd))
		return (1);
	new_cmd_expand(&cmd->cmd, shell);
	shell->exit_status = env(shell);
	dup2(tmp[0], 0);
	dup2(tmp[1], 1);
	if (shell->exit_status == 1)
		ft_dprintf(2, "env: write error: No space left on device\n");
	return (shell->exit_status);
}
