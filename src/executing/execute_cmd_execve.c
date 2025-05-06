/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_execve.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:06:09 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/05 16:35:21 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_before_exit(t_minishell *shell, int fd_in, int fd_out)
{
	ft_free_tab(shell->args);
	ft_free_tab(shell->env);
	ft_free_t_command(shell);
	free(shell->line);
	close_fds_without(0, fd_in, fd_out);
	free(shell);
	rl_clear_history();
}

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
	ft_dprintf(2, "Error: PATH not found\n");
	return (NULL);
}

void	ft_execute_cmd(t_command *cmd, t_minishell *shell)
{
	int		fds[2];
	int		error;
	char	**env;
	char	**cmd_exec;

	redirection(shell, cmd);
	error = 0;
	fds[0] = cmd->fd_in_put;
	fds[1] = cmd->fd_out_put;
	if (ft_dup2(cmd))
	{
		ft_free_before_exit(shell, -1, -1);
		exit(1);
	}
	new_cmd_expand(&cmd->cmd, shell);
	// error = ft_get_path(&cmd->cmd, shell->env, &cmd_exec);
	cmd_exec = ft_tabdup(cmd->cmd);
	env = ft_tabdup(shell->env);
	ft_free_before_exit(shell, cmd->fd_in_put, cmd->fd_out_put);
	ft_dprintf(2, "test = %s, %i\n", cmd_exec[0], error);
	if (!error)
	{
		signals(SIGNAL_DEFAULT);
		execve(cmd_exec[0], cmd_exec, env);
		ft_dprintf(2, "minishell: %s: command not found\n", cmd_exec[0]);
		error = 127;
	}
	ft_free_tab(cmd_exec);
	ft_free_tab(env);
	close(fds[0]);
	close(fds[1]);
	exit(error);
}
