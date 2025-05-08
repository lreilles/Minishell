/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_execve.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:06:09 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/08 07:20:26 by lsellier         ###   ########.fr       */
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

void	ft_execve_without_path(char **cmd_exec, char **env)
{
	signals(SIGNAL_DEFAULT);
	execve(cmd_exec[0], cmd_exec, NULL);
	signals(SIGNAL_IGN);
	ft_dprintf(2, "minishell: %s: No such file or directory\n", cmd_exec[0]);
	ft_free_tab(env);
	ft_free_tab(cmd_exec);
	close_fds(0);
	exit(127);
}

void	ft_execve_with_path(char **cmd_exec, char **env)
{
	signals(SIGNAL_DEFAULT);
	execve(cmd_exec[0], cmd_exec, env);
	signals(SIGNAL_IGN);
	ft_dprintf(2, "minishell: %s: command not found\n", cmd_exec[0]);
	ft_free_tab(env);
	ft_free_tab(cmd_exec);
	close_fds(0);
	exit(127);
}

void	ft_chose_execve(char **cmd_exec, char **env)
{
	char	*path;

	ft_verif_is_directory(cmd_exec, env);
	path = my_getenv(env);
	if (path == NULL || ft_strchr(cmd_exec[0], '/') != NULL)
		ft_execve_without_path(cmd_exec, env);
	path = ft_get_path(cmd_exec[0], env);
	free(cmd_exec[0]);
	cmd_exec[0] = path;
	ft_execve_with_path(cmd_exec, env);
}

void	ft_execute_cmd(t_command *cmd, t_minishell *shell)
{
	char	**env;
	char	**cmd_exec;
	int		exit_code;

	exit_code = 0;
	redirection(shell, cmd);
	if (ft_dup2(cmd))
	{
		ft_free_before_exit(shell, -1, -1);
		exit(1);
	}
	new_cmd_expand(&cmd->cmd, shell);
	cmd_exec = ft_tabdup(cmd->cmd);
	env = ft_tabdup(shell->env);
	ft_free_before_exit(shell, cmd->fd_in_put, cmd->fd_out_put);
	ft_chose_execve(cmd_exec, env);
}
