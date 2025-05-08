/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:51:37 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/07 04:49:01 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_parse_env(t_minishell *shell, t_command *cmd)
{
	int	tmp[2];

	redirection(shell, cmd);
	tmp[0] = 0;
	tmp[1] = 1;
	if (ft_dup2(cmd))
		return (1);
	new_cmd_expand(&cmd->cmd, shell);
	env(shell);
	dup2(tmp[0], 0);
	dup2(tmp[1], 1);
	return (0);
}
