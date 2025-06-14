/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 07:58:56 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/14 03:08:29 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parse_special_cd(t_minishell *shell, t_command *cmd)
{
	if (ft_tablen(cmd->cmd) == 1)
	{
		ft_free_tab(cmd->cmd);
		cmd->cmd = ft_split("cd $HOME", ' ');
		new_cmd_expand(&cmd->cmd, shell);
		if (ft_tablen(cmd->cmd) == 1)
			ft_dprintf(2, "minishell cd: HOME not set\n");
	}
	else if (ft_strcmp(cmd->cmd[1], "-") == 0)
	{
		if (my_getenv(shell->env) == NULL)
			ft_dprintf(2, "minishell: cd: OLDPWD not set\n");
		else
		{
			ft_free_tab(cmd->cmd);
			cmd->cmd = ft_split("cd $OLDPWD", ' ');
			new_cmd_expand(&cmd->cmd, shell);
		}
	}
}

int	ft_parse_cd(t_minishell *shell, t_command *cmd)
{
	int	tmp[2];

	redirection(shell, cmd);
	tmp[0] = dup(0);
	tmp[1] = dup(1);
	if (ft_dup2(shell, cmd))
		return (1);
	new_cmd_expand(&cmd->cmd, shell);
	parse_special_cd(shell, cmd);
	shell->exit_status = ft_cd(shell, cmd->cmd + 1);
	dup2(tmp[0], 0);
	dup2(tmp[1], 1);
	close(tmp[0]);
	close(tmp[1]);
	return (shell->exit_status);
}
