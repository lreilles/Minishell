/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 01:52:01 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/13 05:50:08 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cmds_without_redir(t_command *cmds)
{
	int	i;

	i = 0;
	while (cmds->cmd[i])
	{
		if (ft_strcmp(cmds->cmd[i], "<") == 0 || ft_strcmp(cmds->cmd[i],
				">") == 0 || ft_strcmp(cmds->cmd[i], "<<") == 0
			|| ft_strcmp(cmds->cmd[i], ">>") == 0)
			delete_redirection(cmds, &i);
		i++;
	}
}

int	open_with_error(t_minishell *shell, t_command *cmd, char *file, int flags)
{
	if (flags <= 2)
	{
		if (cmd->fd_in_put != 0 && cmd->fd_in_put != -1)
			close(cmd->fd_in_put);
		cmd->fd_in_put = acess_file(shell, file, flags);
		if (cmd->fd_in_put == 0 || cmd->fd_in_put == -1)
			return (1);
	}
	else
	{
		if (cmd->fd_out_put != 1 && cmd->fd_out_put != -1)
			close(cmd->fd_out_put);
		cmd->fd_out_put = acess_file(shell, file, flags);
		if (cmd->fd_out_put == 1 || cmd->fd_out_put == -1)
			return (1);
	}
	return (0);
}

void	expand_redirect(char *cmd, t_minishell *shell)
{
	char	*str;

	str = without_quotes(cmd);
	if (ft_is_quote(cmd[0]) || ft_strcmp(cmd, "$") == 0)
	{
		ft_dprintf(2, "minishell: %s: No such file or directory\n", str);
		shell->exit_status = 1;
	}
	else
	{
		ft_dprintf(2, "minishell: %s: ambiguous redirect\n", str);
		shell->exit_status = 1;
	}
	free(str);
}

int	open_redirection(t_minishell *shell, t_command *cmd, int i)
{
	char	**tmp;

	tmp = expand_variable(cmd->cmd[i + 1], shell);
	if (tmp == NULL)
		return (1);
	if (ft_tablen(tmp) > 1)
		return (ft_free_tab(tmp), ft_dprintf(2, "minishell: "
				"%s: ambiguous redirect\n", cmd->cmd[i + 1]), 1);
	if (tmp[0][0] == '\0')
		return (ft_free_tab(tmp), expand_redirect(cmd->cmd[i + 1], shell), 1);
	if (ft_strcmp(cmd->cmd[i], "<") == 0)
	{
		if (open_with_error(shell, cmd, tmp[0], 1) == 1)
			return (ft_free_tab(tmp), 1);
	}
	else if (ft_strcmp(cmd->cmd[i], ">") == 0)
	{
		if (open_with_error(shell, cmd, tmp[0], 3) == 1)
			return (ft_free_tab(tmp), 1);
	}
	else if (ft_strcmp(cmd->cmd[i], ">>") == 0)
		if (open_with_error(shell, cmd, tmp[0], 4) == 1)
			return (ft_free_tab(tmp), 1);
	ft_free_tab(tmp);
	return (0);
}

int	redirection(t_minishell *shell, t_command *cmds)
{
	int	i;
	int	error;

	error = 0;
	i = -1;
	while (cmds->cmd[++i])
	{
		if (ft_strcmp(cmds->cmd[i], "<") == 0)
			error = open_redirection(shell, cmds, i);
		else if (ft_strcmp(cmds->cmd[i], ">") == 0)
			error = open_redirection(shell, cmds, i);
		else if (ft_strcmp(cmds->cmd[i], ">>") == 0)
			error = open_redirection(shell, cmds, i);
		else if (ft_strcmp(cmds->cmd[i], "<<") == 0)
			error = open_redirection_heredoc(shell, cmds, i);
		if (error == 1)
			break ;
	}
	if (error == 1)
		return (0);
	cmds_without_redir(cmds);
	return (1);
}
