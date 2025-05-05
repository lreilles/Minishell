/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cmd_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 05:58:17 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/02 06:25:46 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_had_len_of_new_tab(t_minishell *shell, char **cmd)
{
	int		len_new_cmd;
	char	*tmp;
	int		i;

	len_new_cmd = 0;
	i = -1;
	while (cmd[++i])
	{
		tmp = expand_variable(cmd[i], shell->env, shell);
		if (tmp != NULL)
			len_new_cmd++;
		free(tmp);
	}
	return (len_new_cmd);
}

void	new_cmd_expand(char ***cmd, t_minishell *shell)
{
	char	**new_cmd;
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	new_cmd = malloc(sizeof(char *) * (ft_had_len_of_new_tab(shell, *cmd) + 1));
	if (!new_cmd)
		return ;
	i = -1;
	j = 0;
	while ((*cmd)[++i])
	{
		tmp = expand_variable((*cmd)[i], shell->env, shell);
		if ((tmp != NULL && ft_strcmp(tmp, "") != 0) || ft_strncmp((*cmd)[i],
			"$", 1) != 0)
			new_cmd[j++] = expand_variable((*cmd)[i], shell->env, shell);
		free(tmp);
	}
	new_cmd[j] = NULL;
	ft_free_tab((*cmd));
	(*cmd) = new_cmd;
}
