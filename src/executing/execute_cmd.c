/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 07:33:14 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/14 02:15:12 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_execute_lastcmd(t_command *cmd, t_minishell *shell, int or_and)
{
	if (!ft_waitpid(shell, or_and))
		return ;
	if (ft_isbuiltin(cmd, shell) != 0)
		ft_execute_builtin(shell, cmd);
	else
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
			return (close_fds(&shell->fd_list), (void)ft_dprintf(2,
					"minishell: error fork failed\n"));
		if (cmd->pid == 0)
			ft_execute_cmd(cmd, shell);
		ft_add_lst_int(&shell->pid_list, cmd->pid);
	}
	ft_wait_pid_exit_status(shell);
	return ;
}

void	ft_execute_lastcmd_pipe(t_command *cmd, t_minishell *shell)
{
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		ft_dprintf(2, "minishell: error fork failed\n");
		close_fds(&shell->fd_list);
		ft_wait_pid_exit_status(shell);
		return ;
	}
	if (cmd->pid == 0)
	{
		if (ft_isbuiltin(cmd, shell))
			ft_execute_builtin_pipe(shell, cmd);
		else
			ft_execute_cmd(cmd, shell);
	}
	ft_add_lst_int(&shell->pid_list, cmd->pid);
	ft_wait_pid_exit_status(shell);
	return ;
}

void	ft_execute_with_fork(t_command *cmd, t_minishell *shell)
{
	cmd->pid = fork();
	if (cmd->pid == -1)
		return (close_fds(&shell->fd_list), (void)ft_dprintf(2,
				"minishell: error fork failed\n"));
	if (cmd->pid == 0)
	{
		if (ft_isbuiltin(cmd, shell))
			ft_execute_builtin_pipe(shell, cmd);
		else
			ft_execute_cmd(cmd, shell);
	}
	ft_add_lst_int(&shell->pid_list, cmd->pid);
}
