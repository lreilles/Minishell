/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbuiltin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 05:09:05 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/04 13:55:56 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	skip_expand_null(char **cmd, t_minishell *shell, int *i)
{
	char	*tmp;

	while (cmd[*i])
	{
		tmp = expand_variable(cmd[*i], shell->env, shell);
		if (ft_strcmp(cmd[*i], ">") == 0)
			(*i)++;
		else if (ft_strcmp(cmd[*i], ">>") == 0)
			(*i)++;
		else if (ft_strcmp(cmd[*i], "<") == 0)
			(*i)++;
		else if ((tmp != NULL && ft_strcmp(tmp, "") != 0) || ft_strncmp(cmd[*i],
				"$", 1) != 0)
			return ((void)free(tmp));
		(*i)++;
		free(tmp);
	}
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
	if (i == ft_tablen(cmd->cmd))
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
		shell->exit_status = 0;
	// else if (builtin == 2)
	// 	exit_status = ft_cd(shell, cmd);
	else if (builtin == 3)
		shell->exit_status = ft_parse_echo(shell, cmd);
	return ;
}

void	ft_execute_builtin_pipe(t_minishell *shell, t_command *cmd)
{
	int	builtin;
	int	exit_status;

	builtin = ft_isbuiltin(cmd, shell);
	exit_status = 0;
	if (builtin == 1)
		exit_status = 0;
	// else if (builtin == 2)
	// 	exit_status = ft_cd(shell, cmd);
	else if (builtin == 3)
		exit_status = ft_parse_echo(shell, cmd);
	// else if (builtin == 4)
	// 	exit_status = ft_env(shell, cmd);
	// else if (builtin == 5)
	// 	exit_status = ft_exit(shell, cmd);
	// else if (builtin == 6)
	// 	exit_status = ft_export(shell, cmd);
	// else if (builtin == 7)
	// 	exit_status = ft_pwd(shell, cmd);
	// else if (builtin == 8)
	// 	exit_status = ft_unset(shell, cmd);
	close_fds(0);
	ft_free_tab(shell->args);
	ft_free_tab(shell->env);
	ft_free_t_command(shell);
	free(shell->line);
	free(shell);
	exit(exit_status);
}
