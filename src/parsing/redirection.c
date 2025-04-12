/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 01:52:01 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/12 04:09:18 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


t_command	*cmds_without_redir(t_minishell *shell)
{
	t_command	*tmp;
	int			i;

	tmp = shell->cmds;
	while (tmp)
	{
		i = 0;
		while (tmp->cmd[i])
		{
			if (ft_strcmp(tmp->cmd[i], "<") == 0 || ft_strcmp(tmp->cmd[i],
					">") == 0 || ft_strcmp(tmp->cmd[i], "<<") == 0
				|| ft_strcmp(tmp->cmd[i], ">>") == 0)
				delete_redirection(tmp, &i);
			i++;
		}
		tmp = tmp->next;
	}
	return (shell->cmds);
}

int	acess_file(char *file, int flags)
{
	int	fd;

	if (flags == 1)
	{
		if (access(file, F_OK) == -1)
			return (ft_dprintf(2, "minishell: %s: No such file or directory\n",
					file), -1);
		fd = open(file, O_RDONLY, 0644);
	}
	else if (flags == 3)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (flags == 4)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return (-1);
	if (fd == -1)
		return (ft_dprintf(2, "minishell: %s: Permission denied\n", file), -1);
	return (fd);
}

int	open_with_error(t_minishell *shell, t_command *cmd, char *file, int flags)
{
	if (flags <= 2)
	{
		if (shell->cmds->fd_in_put != -1)
			close(shell->cmds->fd_in_put);
		cmd->fd_in_put = acess_file(file, flags);
		if (cmd->fd_in_put == -1)
			return (1);
	}
	else
	{
		if (shell->cmds->fd_out_put != -1)
			close(shell->cmds->fd_out_put);
		cmd->fd_out_put = acess_file(file, flags);
		if (cmd->fd_out_put == -1)
			return (1);
	}
	return (0);
}

int	open_redirection(t_minishell *shell, t_command *cmd, int i)
{
	char	*tmp;

	tmp = expand_variable(cmd->cmd[i + 1], shell->env);
	if (cmd->cmd[i][0] == '<')
	{
		if (open_with_error(shell, cmd, tmp, 1) == 1)
			return (free(tmp), 1);
	}
	else if (cmd->cmd[i][0] == '>')
	{
		if (open_with_error(shell, cmd, tmp, 3) == 1)
			return (free(tmp), 1);
	}
	else if (ft_strcmp(cmd->cmd[i], ">>"))
	{
		if (open_with_error(shell, cmd, tmp, 4) == 1)
			return (free(tmp), 1);
	}
	free(tmp);
	return (0);
}

t_command	*redirection(t_minishell *shell)
{
	t_command	*tmp;
	int			i;
	int			error;

	tmp = shell->cmds;
	error = 0;
	while (tmp)
	{
		i = -1;
		while (tmp->cmd[++i])
		{
			if (ft_strcmp(tmp->cmd[i], "<") == 0)
				error = open_redirection(shell, tmp, i);
			else if (ft_strcmp(tmp->cmd[i], ">") == 0)
				error = open_redirection(shell, tmp, i);
			else if (ft_strcmp(tmp->cmd[i], ">>") == 0)
				error = open_redirection(shell, tmp, i);
			if (error == 1)
				break ;
		}
		tmp = tmp->next;
	}
	if (error == 1)
		return (close_fds(3), ft_free_t_command(shell), NULL);
	return (cmds_without_redir(shell));
}
