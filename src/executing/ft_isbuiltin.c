/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbuiltin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 05:09:05 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/08 07:51:41 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parse_nothing(t_minishell *shell, t_command *cmd)
{
	int	tmp[2];

	if (!redirection(shell, cmd))
		return (1);
	tmp[0] = dup(0);
	tmp[1] = dup(1);
	if (ft_dup2(cmd))
		return (1);
	dup2(tmp[0], 0);
	dup2(tmp[1], 1);
	close_fds(3);
	close(tmp[0]);
	close(tmp[1]);
	return (0);
}

void	skip_expand_null(char **cmd, t_minishell *shell, int *i)
{
	char	**tmp;

	while (cmd[*i])
	{
		tmp = expand_variable(cmd[*i], shell);
		if (ft_strcmp(cmd[*i], ">") == 0)
			(*i)++;
		else if (ft_strcmp(cmd[*i], ">>") == 0)
			(*i)++;
		else if (ft_strcmp(cmd[*i], "<") == 0)
			(*i)++;
		else if (ft_strcmp(cmd[*i], "<<") == 0)
			(*i)++;
		else if ((tmp[0] != NULL && ft_strcmp(tmp[0], "") != 0)
			|| ft_strncmp(cmd[*i], "$", 1) != 0)
			return (ft_free_tab(tmp));
		(*i)++;
		ft_free_tab(tmp);
	}
}

int	ft_isbuiltin(t_command *cmd, t_minishell *shell)
{
	int		i;
	char	**tmp;

	i = 0;
	skip_expand_null(cmd->cmd, shell, &i);
	tmp = expand_variable(cmd->cmd[i], shell);
	if (i == ft_tablen(cmd->cmd))
		return (ft_free_tab(tmp), 1);
	else if (ft_strcmp(tmp[0], "cd") == 0)
		return (ft_free_tab(tmp), 2);
	else if (ft_strcmp(tmp[0], "echo") == 0)
		return (ft_free_tab(tmp), 3);
	else if (ft_strcmp(tmp[0], "env") == 0)
		return (ft_free_tab(tmp), 4);
	else if (ft_strcmp(tmp[0], "exit") == 0)
		return (ft_free_tab(tmp), 5);
	else if (ft_strcmp(tmp[0], "export") == 0)
		return (ft_free_tab(tmp), 6);
	else if (ft_strcmp(tmp[0], "pwd") == 0)
		return (ft_free_tab(tmp), 7);
	else if (ft_strcmp(tmp[0], "unset") == 0)
		return (ft_free_tab(tmp), 8);
	return (ft_free_tab(tmp), 0);
}

void	ft_execute_builtin(t_minishell *shell, t_command *cmd)
{
	int	builtin;

	builtin = ft_isbuiltin(cmd, shell);
	if (builtin == 1)
		shell->exit_status = parse_nothing(shell, cmd);
	// else if (builtin == 2)
	// 	exit_status = ft_cd(shell, cmd);
	else if (builtin == 3)
		shell->exit_status = ft_parse_echo(shell, cmd);
	else if (builtin == 4)
		shell->exit_status = ft_parse_env(shell, cmd);
	return ;
}

void	ft_execute_builtin_pipe(t_minishell *shell, t_command *cmd)
{
	int	builtin;
	int	exit_status;

	builtin = ft_isbuiltin(cmd, shell);
	exit_status = 0;
	if (builtin == 1)
		exit_status = parse_nothing(shell, cmd);
	// else if (builtin == 2)
	// 	exit_status = ft_cd(shell, cmd);
	else if (builtin == 3)
		exit_status = ft_parse_echo(shell, cmd);
	else if (builtin == 4)
		exit_status = ft_parse_env(shell, cmd);
	// else if (builtin == 5)
	// 	exit_status = ft_exit(shell, cmd);
	// else if (builtin == 6)
	// 	exit_status = ft_export(shell, cmd);
	// else if (builtin == 7)
	// 	exit_status = ft_pwd(shell, cmd);
	// else if (builtin == 8)
	// 	exit_status = ft_unset(shell, cmd);
	ft_free_before_exit(shell, -1, -1);
	close_fds(0);
	exit(exit_status);
}
