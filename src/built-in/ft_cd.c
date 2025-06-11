/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <ameduboi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:32:35 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/12 01:40:27 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cd(t_minishell *minishell, char **cmd)
{
	int		verif;
	char	*path;
	int		tmp;
	char	*tmp_pwd;

	path = NULL;
	tmp = 0;
	if (ft_tablen(cmd) > 1)
		return (ft_dprintf(2, "minishell: cd: too many arguments\n"), 1);
	verif = chdir(cmd[0]);
	if (verif < 0)
		return (ft_dprintf(2, "cd: %s: No such file or directory\n", cmd[0]),
			1);
	path = getcwd(NULL, 0);
	tmp_pwd = get_env_value(minishell, minishell->env, "PWD", &tmp);
	if (tmp_pwd)
		edit_env_value(minishell, "OLDPWD", tmp_pwd);
	if (path)
		edit_env_value(minishell, "PWD", path);
	free(tmp_pwd);
	free(path);
	return (0);
}
