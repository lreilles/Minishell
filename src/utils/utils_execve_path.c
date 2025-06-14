/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_execve_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 07:19:37 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/14 02:23:47 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*my_getenv(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

void	ft_verif_is_directory(char **cmd_exec, char **env)
{
	struct stat	stat_struct;

	if (stat(cmd_exec[0], &stat_struct) != -1)
	{
		if (S_ISDIR(stat_struct.st_mode))
		{
			ft_dprintf(2, "minishell: %s: Is a directory\n", cmd_exec[0]);
			ft_free_tab(env);
			ft_free_tab(cmd_exec);
			exit(126);
		}
	}
}

char	*ft_get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;

	i = -1;
	allpath = ft_split(my_getenv(env), ':');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (ft_free_tab(allpath), exec);
		free(exec);
	}
	return (ft_free_tab(allpath), ft_strdup(cmd));
}
