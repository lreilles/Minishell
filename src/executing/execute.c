/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 04:52:34 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/06 01:21:48 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	*have_static_int(int nbr)
{
	static int	i;

	if (nbr == 0)
		i = 0;
	return (&i);
}

int	next_separator(char **args)
{
	int	*i;

	i = have_static_int(1);
	while (args[(*i)])
	{
		if (ft_strcmp(args[(*i)], "|") == 0)
			return ((*i)++, 1);
		else if (ft_strcmp(args[(*i)], "||") == 0)
			return ((*i)++, 2);
		else if (ft_strcmp(args[(*i)], "&&") == 0)
			return ((*i)++, 3);
		(*i)++;
	}
	return (0);
}

void	ft_wait_all_pid_without_last(t_minishell *shell)
{
	int		status;
	pid_t	pid;
	t_pid	*tmp;

	if (!shell->pid_list)
		return ;
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

t_pid	*ft_add_pid(t_pid *pid_list, pid_t pid)
{
	t_pid	*new;

	new = malloc(sizeof(t_pid));
	if (!new)
		return (NULL);
	new->pid = pid;
	new->next = pid_list;
	return (new);
}

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
		{
			ft_dprintf(2, "minishell: error fork failed\n");
			close_fds(3);
			return ;
		}
		if (cmd->pid == 0)
			ft_execute_cmd(cmd, shell);
		shell->pid_list = ft_add_pid(shell->pid_list, cmd->pid);
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
		close_fds(3);
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
	shell->pid_list = ft_add_pid(shell->pid_list, cmd->pid);
	ft_wait_pid_exit_status(shell);
	return ;
}

void	ft_execute_pipe(t_command *cmd, t_minishell *shell, int or_and)
{
	int	pipefd[2];
	int	separator;

	if (!ft_waitpid(shell, or_and))
		return ;
	if (pipe(pipefd) == -1)
		return ((void)ft_dprintf(2, "minishell: error pipe failed\n"));
	cmd->fd_out_put = pipefd[1];
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		ft_dprintf(2, "minishell: error fork failed\n");
		close_fds(3);
		return ;
	}
	if (cmd->pid == 0)
	{
		cmd->fd_out_put = pipefd[1];
		if (ft_isbuiltin(cmd, shell))
			ft_execute_builtin_pipe(shell, cmd);
		else
			ft_execute_cmd(cmd, shell);
	}
	shell->pid_list = ft_add_pid(shell->pid_list, cmd->pid);
	cmd->next->fd_in_put = pipefd[0];
	cmd = cmd->next;
	separator = next_separator(shell->args);
	if (separator == 1)
		ft_execute_pipe(cmd, shell, 0);
	else if (separator == 2)
		ft_execute_or(cmd, shell, 0, 1);
	else if (separator == 3)
		ft_execute_and(cmd, shell, 0, 1);
	else
		ft_execute_lastcmd_pipe(cmd, shell);
}

void	ft_execute_with_fork(t_command *cmd, t_minishell *shell)
{
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		ft_dprintf(2, "minishell: error fork failed\n");
		close_fds(3);
		return ;
	}
	if (cmd->pid == 0)
	{
		if (ft_isbuiltin(cmd, shell))
			ft_execute_builtin_pipe(shell, cmd);
		else
			ft_execute_cmd(cmd, shell);
	}
	shell->pid_list = ft_add_pid(shell->pid_list, cmd->pid);
}

void	ft_execute_and(t_command *cmd, t_minishell *shell, int or_and,
		int ispipe)
{
	int	separator;

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
			close_fds(3);
			return ;
		}
		if (cmd->pid == 0)
			ft_execute_cmd(cmd, shell);
		shell->pid_list = ft_add_pid(shell->pid_list, cmd->pid);
	}
	cmd = cmd->next;
	separator = next_separator(shell->args);
	if (separator == 1)
		ft_execute_pipe(cmd, shell, 1);
	else if (separator == 2)
		ft_execute_or(cmd, shell, 1, 0);
	else if (separator == 3)
		ft_execute_and(cmd, shell, 1, 0);
	else
		ft_execute_lastcmd(cmd, shell, 1);
}

void	ft_execute_or(t_command *cmd, t_minishell *shell, int or_and,
		int ispipe)
{
	int	separator;

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
		{
			ft_dprintf(2, "minishell: error fork failed\n");
			close_fds(3);
			return ;
		}
		if (cmd->pid == 0)
			ft_execute_cmd(cmd, shell);
		shell->pid_list = ft_add_pid(shell->pid_list, cmd->pid);
	}
	cmd = cmd->next;
	separator = next_separator(shell->args);
	if (separator == 1)
		ft_execute_pipe(cmd, shell, 2);
	else if (separator == 2)
		ft_execute_or(cmd, shell, 2, 0);
	else if (separator == 3)
		ft_execute_and(cmd, shell, 2, 0);
	else
		ft_execute_lastcmd(cmd, shell, 2);
}

void	ft_execute_cmds(t_minishell *shell)
{
	int	separator;

	have_static_int(0);
	separator = next_separator(shell->args);
	if (separator == 1)
		ft_execute_pipe(shell->cmds, shell, 0);
	else if (separator == 2)
		ft_execute_or(shell->cmds, shell, 0, 0);
	else if (separator == 3)
		ft_execute_and(shell->cmds, shell, 0, 0);
	else
		ft_execute_lastcmd(shell->cmds, shell, 0);
	ft_free_t_command(shell);
	ft_free_tab(shell->args);
	close_fds(3);
		int	i;

	for (i = 0; i < getdtablesize(); i++)
	{
		if (fcntl(i, F_GETFD) != -1)
		{
			ft_dprintf(2, "Error: File descriptor %d is still open\n", i);
		}
	}
}
