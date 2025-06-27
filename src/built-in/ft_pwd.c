/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:31:25 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/27 01:27:58 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pwd(t_minishell *shell)
{
	char	*path;
	int		verif;

	path = getcwd(NULL, 0);
	if (!path)
	{
		path = get_env_value(shell, shell->env, "PWD", &verif);
		if (ft_strcmp(path, "") == 0)
			return (ft_dprintf(2,
					"minishell: pwd: No such file or directory\n"), 1);
		else
			return (ft_dprintf(1, "%s\n", path), 0);
	}
	verif = ft_printf("%s\n", path);
	if (verif < 0)
	{
		ft_dprintf(2, "minishell: pwd: write error: No space left on device\n");
		free(path);
		return (1);
	}
	free(path);
	return (0);
}
