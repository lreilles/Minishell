/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:35:57 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/12 04:09:22 by lsellier         ###   ########.fr       */
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

char	**ft_tab_j_to_i(char **args, int j, int i)
{
	char	**tab;
	int		k;

	k = 0;
	tab = malloc(sizeof(char *) * (i - j + 1));
	while (args[j] && j < i)
	{
		tab[k] = ft_strdup(args[j]);
		j++;
		k++;
	}
	tab[k] = NULL;
	return (tab);
}

void	ft_add_cmd(t_command **cmd, t_command *tmp)
{
	t_command	*current;

	if (!*cmd)
	{
		*cmd = tmp;
		return ;
	}
	current = *cmd;
	while (current->next)
		current = current->next;
	current->next = tmp;
}

t_command	*creat_cmds(t_minishell *shell)
{
	t_command	*cmd;
	t_command	*tmp;
	int			i;
	int			j;

	i = 1;
	cmd = NULL;
	j = 0;
	while (i <= shell->nb_args)
	{
		if ((shell->args[i] != NULL && (ft_issplit_cmd(shell->args[i])))
			|| shell->args[i] == NULL)
		{
			tmp = malloc(sizeof(t_command));
			tmp->cmd = ft_tab_j_to_i(shell->args, j, i);
			tmp->next = NULL;
			tmp->fd_in_put = -1;
			tmp->fd_out_put = -1;
			tmp->pid = -1;
			ft_add_cmd(&cmd, tmp);
			j = i + 1;
		}
		i++;
	}
	return (cmd);
}
