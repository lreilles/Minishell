/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbuiltin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 05:09:05 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/28 23:52:22 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	skip_expand_null(char **cmd, t_minishell *shell, int *i)
{
	char	*tmp;

	while (cmd[*i])
	{
		tmp = expand_variable(cmd[*i], shell->env, shell);
		ft_dprintf(2, "test cmd->cmd[%i] = %s\n", *i, cmd[*i]);
		if (ft_strcmp(cmd[*i], ">") == 0)
			(*i)++;
		else if (ft_strcmp(cmd[*i], ">>") == 0)
			(*i)++;
		else if (ft_strcmp(cmd[*i], "<") == 0)
			(*i)++;
		else if ((tmp != NULL && ft_strcmp(tmp, "") != 0) || ft_strncmp(cmd[*i],
				"$", 1) != 0)
			return ((void)free(tmp));
		(*i)++;
		free(tmp);
	}
}
