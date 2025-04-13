/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 01:52:01 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/13 07:40:53 by lsellier         ###   ########.fr       */
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

int	open_with_error(t_minishell *shell, t_command *cmd, char *file, int flags)
{
	if (flags <= 2)
	{
		if (shell->cmds->fd_in_put != -1)
			close(shell->cmds->fd_in_put);
		cmd->fd_in_put = acess_file(shell, file, flags);
		if (cmd->fd_in_put == -1)
			return (1);
	}
	else
	{
		if (shell->cmds->fd_out_put != -1)
			close(shell->cmds->fd_out_put);
		cmd->fd_out_put = acess_file(shell, file, flags);
		if (cmd->fd_out_put == -1)
			return (1);
	}
	return (0);
}

void	error_expand_redirect(char *cmd, t_minishell *shell)
{
	int		i;
	char	*str;

	i = 0;
	ft_printf("cmd = %s\n", cmd);
	str = without_quotes(cmd);
	if (ft_is_quote(cmd[0]) || strcmp(cmd, "$") == 0)
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
	char	*tmp;

	tmp = expand_variable(cmd->cmd[i + 1], shell->env, shell);
	if (tmp[0] == '\0')
		return (free(tmp), error_expand_redirect(cmd->cmd[i + 1], shell), 1);
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
