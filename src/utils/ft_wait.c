/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 07:31:28 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/15 16:29:20 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_wait_all_pid_without_last(t_minishell *shell)
{
	int			status;
	pid_t		pid;
	t_lst_int	*tmp;

	if (!shell->pid_list)
		return ;
	close_fds(&shell->fd_list);
	while (shell->pid_list->next)
	{
		pid = shell->pid_list->nbr;
		waitpid(pid, &status, 0);
		tmp = shell->pid_list;
		shell->pid_list = shell->pid_list->next;
		free(tmp);
	}
}

int	ft_wait_all_pid(t_minishell *shell)
{
	int			status;
	t_lst_int	*tmp;

	ft_wait_all_pid_without_last(shell);
	tmp = shell->pid_list;
	waitpid(shell->pid_list->nbr, &status, 0);
	free(tmp);
	shell->pid_list = NULL;
	return (status);
}

int	have_exit_status(t_minishell *shell, int status, int or_and)
{
	if (WCOREDUMP(status) && WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
	{
		ft_dprintf(2, "Quit (core dumped)\n");
		if (or_and == 1)
			return (shell->exit_status = 131, 0);
		else
			return (shell->exit_status = 131, 1);
	}
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		return (ft_dprintf(2, "\n"), shell->exit_status = 130, 0);
	if (or_and == 1)
	{
		status = WEXITSTATUS(status);
		if (status)
			return (shell->exit_status = WEXITSTATUS(status), 0);
	}
	else if (or_and == 2)
	{
		status = WEXITSTATUS(status);
		if (!status)
			return (shell->exit_status = WEXITSTATUS(status), 0);
	}
	return (1);
}

int	ft_waitpid(t_minishell *shell, int or_and)
{
	int		status;

	if (or_and)
	{
		if (or_and == 1)
		{
			if (!shell->pid_list)
				return (!shell->exit_status);
			status = ft_wait_all_pid(shell);
			if (!have_exit_status(shell, status, or_and))
				return (0);
		}
		else if (or_and == 2)
		{
			if (!shell->pid_list)
				return (shell->exit_status);
			status = ft_wait_all_pid(shell);
			if (!have_exit_status(shell, status, or_and))
				return (0);
		}
	}
	return (1);
}

void	ft_wait_pid_exit_status(t_minishell *shell)
{
	int		status;

	if (!shell->pid_list)
		return ;
	ft_wait_all_pid_without_last(shell);
	waitpid(shell->pid_list->nbr, &status, 0);
	shell->exit_status = WEXITSTATUS(status);
	have_exit_status(shell, status, 0);
}
