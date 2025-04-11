/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 01:52:01 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/11 06:45:26 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	delete_redirection(t_command *cmd, int *i)
{
	char	**res;
	int		j;
	int		k;

	j = 0;
	k = 0;
	res = malloc(sizeof(char *) * (ft_tablen(cmd->cmd) - 1));
	if (!res)
		return ;
	while (j < (ft_tablen(cmd->cmd)))
	{
		if (j != (*i) && j != (*i) + 1)
		{
			res[k] = ft_strdup(cmd->cmd[j]);
			k++;
		}
		j++;
	}
	res[k] = NULL;
	(*i) = -1;
	ft_free_tab(cmd->cmd);
	cmd->cmd = res;
}

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

void	open_redirection(t_minishell *shell, t_command *cmd, int i)
{
	char	*tmp;

	tmp = expand_variable(cmd->cmd[i + 1], shell->env);
	if (cmd->cmd[i][0] == '<')
		cmd->fd_in_put = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (cmd->cmd[i][0] == '>')
		cmd->fd_out_put = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (ft_strcmp(cmd->cmd[i], ">>"))
		cmd->fd_out_put = open(tmp, O_WRONLY | O_CREAT | O_APPEND, 0644);
	free(tmp);
}

t_command	*redirection(t_minishell *shell)
{
	t_command	*tmp;
	int			i;

	tmp = shell->cmds;
	while (tmp)
	{
		i = 0;
		while (tmp->cmd[i])
		{
			if (ft_strcmp(tmp->cmd[i], "<") == 0)
				open_redirection(shell, tmp, i);
			else if (ft_strcmp(tmp->cmd[i], ">") == 0)
				open_redirection(shell, tmp, i);
			else if (ft_strcmp(tmp->cmd[i], ">>") == 0)
				open_redirection(shell, tmp, i);
			i++;
		}
		tmp = tmp->next;
	}
	return (cmds_without_redir(shell));
}
