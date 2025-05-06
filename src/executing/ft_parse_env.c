/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:51:37 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/05 16:35:38 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_parse_env(t_minishell *shell, t_command *cmd)
{
	redirection(shell, cmd);
	if (ft_dup2(cmd))
		return (1);
	new_cmd_expand(&cmd->cmd, shell);
	env(shell->env);
	return (0);
}
