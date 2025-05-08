/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:41:55 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/07 04:49:12 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_skip_flag_n(t_command *cmd, int *i)
{
	int	j;
	int	flag;

	(*i) = 1;
	flag = 0;
	while (cmd->cmd[(*i)])
	{
		if (ft_strncmp(cmd->cmd[(*i)], "-n", 2) == 0)
		{
			j = 1;
			while (cmd->cmd[(*i)][j] == 'n')
				j++;
			if (cmd->cmd[(*i)][j] == '\0')
				flag = 1;
			else
				break ;
			(*i)++;
		}
		else
			break ;
	}
	return (flag);
}

int	ft_parse_echo(t_minishell *shell, t_command *cmd)
{
	int	flag;
	int	i;
	int	tmp[2];

	if (!redirection(shell, cmd))
		return (1);
	tmp[0] = dup(0);
	tmp[1] = dup(1);
	i = -1;
	if (ft_dup2(cmd))
		return (1);
	new_cmd_expand(&cmd->cmd, shell);
	flag = ft_skip_flag_n(cmd, &i);
	ft_echo(cmd->cmd + i, flag);
	dup2(tmp[0], 0);
	dup2(tmp[1], 1);
	return (0);
}
