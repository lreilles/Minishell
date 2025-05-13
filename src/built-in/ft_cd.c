/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:32:35 by ameduboi          #+#    #+#             */
/*   Updated: 2025/05/13 02:32:54 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cd(t_minishell *minishell, char **cmd)
{
	int		verif;
	char	*path;

	if (ft_tablen(cmd) > 1)
		return (ft_dprintf(2, "minishell: cd: too many arguments\n"), 1);
	verif = chdir(cmd[0]);
	if (verif < 0)
		return (1);
	path = get_env_value(minishell, minishell->env, "PWD", NULL);
	if (path)
	{
		free(path);
		edit_env_value(minishell, "PWD", cmd[0]);
	}
	free(path);
	return (0);
}
