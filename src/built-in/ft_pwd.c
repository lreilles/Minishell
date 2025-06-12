/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <ameduboi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:31:25 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/12 03:20:32 by ameduboi         ###   ########.fr       */
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
			ft_dprintf(2, "minishell: pwd: No such file or directory\n");
		else
			ft_dprintf(2, "minishell: pwd: %s: No such directory\n", path);
		return (free(path), 1);
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
