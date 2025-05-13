/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 08:22:20 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/14 01:23:32 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_parse_pwd(t_minishell *shell, t_command *cmd)
{
	int	tmp[2];

	redirection(shell, cmd);
	tmp[0] = dup(0);
	tmp[1] = dup(1);
	if (ft_dup2(cmd))
		return (1);
	new_cmd_expand(&cmd->cmd, shell);
	shell->exit_status = pwd();
	if (shell->exit_status == 1)
		ft_dprintf(2, "minishell: pwd: write error: No space left on device\n");
	dup2(tmp[0], 0);
	dup2(tmp[1], 1);
	return (shell->exit_status);
}
