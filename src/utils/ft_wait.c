/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 07:31:28 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/09 04:27:25 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_wait_all_pid_without_last(t_minishell *shell)
{
	int		status;
	pid_t	pid;
	t_pid	*tmp;

	if (!shell->pid_list)
		return ;
	close_fds(3);
	while (shell->pid_list->next)
	{
		pid = shell->pid_list->pid;
		waitpid(pid, &status, 0);
		tmp = shell->pid_list;
		shell->pid_list = shell->pid_list->next;
		free(tmp);
	}
}

int	ft_waitpid(t_minishell *shell, int or_and)
{
	int		status;
	t_pid	*tmp;

	if (or_and)
	{
		if (or_and == 1)
		{
			if (!shell->pid_list)
				return (!shell->exit_status);
			ft_wait_all_pid_without_last(shell);
			tmp = shell->pid_list;
			waitpid(shell->pid_list->pid, &status, 0);
			free(tmp);
			shell->pid_list = NULL;
			if (!WIFEXITED(status))
				return (shell->exit_status = WEXITSTATUS(status), 0);
		}
		else if (or_and == 2)
		{
			if (!shell->pid_list)
				return (shell->exit_status);
			ft_wait_all_pid_without_last(shell);
			tmp = shell->pid_list;
			waitpid(shell->pid_list->pid, &status, 0);
			free(tmp);
			shell->pid_list = NULL;
			if (WIFEXITED(status))
				return (shell->exit_status = WEXITSTATUS(status), 0);
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
	waitpid(shell->pid_list->pid, &status, 0);
	shell->exit_status = WEXITSTATUS(status);
}
