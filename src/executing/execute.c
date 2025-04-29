/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 04:52:34 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/29 02:05:12 by lsellier         ###   ########.fr       */
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
			return (1);
		else if (ft_strcmp(args[(*i)], "||") == 0)
			return (2);
		else if (ft_strcmp(args[(*i)], "&&") == 0)
			return (3);
		(*i)++;
	}
	return (0);
}

void	ft_wait_all_pid_without_last(t_minishell *shell)
{
	int		status;
	pid_t	pid;

	if (!shell->pid_list)
		return ;
	while (shell->pid_list->next)
	{
		pid = shell->pid_list->pid;
		waitpid(pid, &status, 0);
		shell->pid_list = shell->pid_list->next;
	}
}

int	ft_waitpid(t_minishell *shell, int or_and)
{
	int	status;

	if (or_and)
	{
		if (or_and == 1)
		{
			ft_wait_all_pid_without_last(shell);
			waitpid(shell->pid_list->pid, &status, 0);
			if (WIFEXITED(status))
				return (shell->exit_status = WEXITSTATUS(status), 0);
		}
		else if (or_and == 2)
		{
			ft_wait_all_pid_without_last(shell);
			waitpid(shell->pid_list->pid, &status, 0);
			if (!WIFEXITED(status))
				return (0);
		}
	}
	return (1);
}

void	ft_wait_all_pid(t_minishell *shell)
{
	int		status;
	pid_t	pid;
	t_pid	*tmp;

	while (shell->pid_list)
	{
		tmp = shell->pid_list->next;
		pid = shell->pid_list->pid;
		waitpid(pid, &status, 0);
		free(shell->pid_list);
		shell->pid_list = tmp;
	}
	free(shell->pid_list);
	shell->pid_list = NULL;
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

int	ft_isbuiltin(t_command *cmd, t_minishell *shell)
{
	char	**env;
	int		i;
	char	*tmp;

	i = 0;
	env = shell->env;
	skip_expand_null(cmd->cmd, shell, &i);
	tmp = expand_variable(cmd->cmd[i], env, shell);
	if (ft_strcmp(tmp, "") == 0)
		return (free(tmp), 1);
	else if (ft_strcmp(tmp, "cd") == 0)
		return (free(tmp), 2);
	else if (ft_strcmp(tmp, "echo") == 0)
		return (free(tmp), 3);
	else if (ft_strcmp(tmp, "env") == 0)
		return (free(tmp), 4);
	else if (ft_strcmp(tmp, "exit") == 0)
		return (free(tmp), 5);
	else if (ft_strcmp(tmp, "export") == 0)
		return (free(tmp), 6);
	else if (ft_strcmp(tmp, "pwd") == 0)
		return (free(tmp), 7);
	else if (ft_strcmp(tmp, "unset") == 0)
		return (free(tmp), 8);
	return (free(tmp), 0);
}

void	ft_execute_builtin(t_minishell *shell, t_command *cmd)
{
	int	builtin;

	builtin = ft_isbuiltin(cmd, shell);
	if (builtin == 1)
		return ((void)ft_dprintf(2, "test execute builtin\n"));
	return ;
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
			ft_execute_cmd(cmd, shell, 1);
		shell->pid_list = ft_add_pid(shell->pid_list, cmd->pid);
	}
	ft_wait_all_pid(shell);
	return ;
}

void	ft_execute_pipe(t_command *cmd, t_minishell *shell, int or_and)
{
	int	pipefd[2];
	int	separator;

	if (!ft_waitpid(shell, or_and))
		return ;
	if (pipe(pipefd) == -1)
	{
		ft_dprintf(2, "minishell: error pipe failed\n");
		return ;
	}
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
			ft_execute_cmd(cmd, shell, pipefd[1]);
		shell->pid_list = ft_add_pid(shell->pid_list, cmd->pid);
		cmd->next->fd_in_put = pipefd[0];
	}
	cmd = cmd->next;
	separator = next_separator(shell->args);
	if (separator == 1)
		ft_execute_pipe(cmd, shell, 0);
	else if (separator == 2)
		ft_execute_or(cmd, shell, 0);
	else if (separator == 3)
		ft_execute_and(cmd, shell, 0);
	else
		ft_execute_lastcmd(cmd, shell, 0);
}

void	ft_execute_and(t_command *cmd, t_minishell *shell, int or_and)
{
	int	separator;

	if (!ft_waitpid(shell, or_and))
		return ;
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
			ft_execute_cmd(cmd, shell, 1);
		shell->pid_list = ft_add_pid(shell->pid_list, cmd->pid);
		cmd->next->fd_in_put = 0;
	}
	cmd = cmd->next;
	separator = next_separator(shell->args);
	if (separator == 1)
		ft_execute_pipe(cmd, shell, 1);
	else if (separator == 2)
		ft_execute_or(cmd, shell, 1);
	else if (separator == 3)
		ft_execute_and(cmd, shell, 1);
	else
		ft_execute_lastcmd(cmd, shell, 1);
}

void	ft_execute_cmd(t_command *cmd, t_minishell *shell, int fd)
{
	(void)fd;
	(void)cmd;
	(void)shell;
	ft_free_tab(shell->args);
	ft_free_tab(shell->env);
	ft_free_t_pid(shell->pid_list);
	ft_free_t_command(shell);
	free(shell->line);
	close_fds(0);
	free(shell);
	rl_clear_history();
	exit(0);
}

void	ft_execute_or(t_command *cmd, t_minishell *shell, int or_and)
{
	int	separator;

	if (!ft_waitpid(shell, or_and))
		return ;
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
			ft_execute_cmd(cmd, shell, 1);
		shell->pid_list = ft_add_pid(shell->pid_list, cmd->pid);
		cmd->next->fd_in_put = 0;
	}
	cmd = cmd->next;
	separator = next_separator(shell->args);
	if (separator == 1)
		ft_execute_pipe(cmd, shell, 2);
	else if (separator == 2)
		ft_execute_or(cmd, shell, 2);
	else if (separator == 3)
		ft_execute_and(cmd, shell, 2);
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
		ft_execute_or(shell->cmds, shell, 0);
	else if (separator == 3)
		ft_execute_and(shell->cmds, shell, 0);
	else
		ft_execute_lastcmd(shell->cmds, shell, 0);
	ft_free_t_command(shell);
	ft_free_tab(shell->args);
	close_fds(3);
}
