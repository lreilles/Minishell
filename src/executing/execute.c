/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 04:52:34 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/14 02:50:07 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_add_lst_int(t_lst_int **list_int, int nbr)
{
	t_lst_int	*new;
	t_lst_int	*last;

	new = malloc(sizeof(t_lst_int));
	if (!new)
		return (nbr);
	new->nbr = nbr;
	new->next = NULL;
	if (!(*list_int))
		return ((*list_int) = new, nbr);
	last = (*list_int);
	while (last->next)
		last = last->next;
	last->next = new;
	return (nbr);
}

void	ft_execute_pipe(t_command *cmd, t_minishell *shell, int or_and)
{
	int	pipefd[2];

	if (!ft_waitpid(shell, or_and))
		return ;
	if (pipe(pipefd) == -1)
		return ((void)ft_dprintf(2, "minishell: error pipe failed\n"));
	cmd->fd_out_put = ft_add_lst_int(&shell->fd_list, pipefd[1]);
	cmd->next->fd_in_put = ft_add_lst_int(&shell->fd_list, pipefd[0]);
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
	cmd = cmd->next;
	ft_chose_next_separator_pipe(cmd, shell, 0);
}

void	ft_execute_and(t_command *cmd, t_minishell *shell, int or_and,
		int ispipe)
{
	if (!ft_waitpid(shell, or_and))
		return ;
	if (ispipe)
		ft_execute_with_fork(cmd, shell);
	else if (ft_isbuiltin(cmd, shell))
		ft_execute_builtin(shell, cmd);
	else
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
		{
			ft_dprintf(2, "minishell: error fork failed\n");
			close_fds(&shell->fd_list);
			return ;
		}
		if (cmd->pid == 0)
			ft_execute_cmd(cmd, shell);
		ft_add_lst_int(&shell->pid_list, cmd->pid);
	}
	cmd = cmd->next;
	ft_chose_next_separator(cmd, shell, 1);
}

void	ft_execute_or(t_command *cmd, t_minishell *shell, int or_and,
		int ispipe)
{
	if (!ft_waitpid(shell, or_and))
		return ;
	if (ispipe)
		ft_execute_with_fork(cmd, shell);
	if (ft_isbuiltin(cmd, shell))
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
	cmd = cmd->next;
	ft_chose_next_separator(cmd, shell, 2);
}

void	ft_execute_cmds(t_minishell *shell)
{
	have_static_int(0);
	ft_chose_next_separator(shell->cmds, shell, 0);
	ft_free_t_command(shell);
	ft_free_tab(shell->args);
	unlink_all_tmp(shell->nbr_file);
	if (shell->exit)
	{
		close_fds(&shell->fd_list);
		free(shell->line);
		exit(free_struct(shell));
	}
	close_fds(&shell->fd_list);
}
