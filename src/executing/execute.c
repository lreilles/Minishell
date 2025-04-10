/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 04:52:34 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/11 01:45:07 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_issplit_cmd(char *str)
{
	if (!ft_strcmp(str, "|") || !ft_strcmp(str, "||") || !ft_strcmp(str, "&&"))
		return (1);
	return (0);
}

void	ft_execute_cmds(t_minishell *shell)
{
	int	i;
	int	count_cmds;

	i = 0;
	count_cmds = 1;
	while (shell->args[i] != NULL)
	{
		if (ft_issplit_cmd(shell->args[i]))
			count_cmds++;
		i++;
	}
	ft_free_t_command(shell);
	ft_free_tab(shell->args);
}
