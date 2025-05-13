/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 07:58:56 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/13 02:32:23 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_parse_cd(t_minishell *shell, t_command *cmd)
{
	int		tmp[2];
	char	**tab_tmp;

	redirection(shell, cmd);
	tmp[0] = 0;
	tmp[1] = 1;
	if (ft_dup2(cmd))
		return (1);
	new_cmd_expand(&cmd->cmd, shell);
	if (ft_tablen(cmd->cmd) == 1)
	{
		tab_tmp = ft_split("cd $HOME", ' ');
		new_cmd_expand(&tab_tmp, shell);
		ft_free_tab(cmd->cmd);
		cmd->cmd = tab_tmp;
		if (ft_tablen(cmd->cmd) == 1)
			return (ft_dprintf(2, "minishell cd: HOME not set\n"), 1);
	}
	shell->exit_status = ft_cd(shell, cmd->cmd + 1);
	dup2(tmp[0], 0);
	dup2(tmp[1], 1);
	return (shell->exit_status);
}
