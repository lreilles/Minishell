/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cmd_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 05:58:17 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/07 03:47:31 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_had_len_of_new_tab(t_minishell *shell, char **cmd)
{
	int		len_new_cmd;
	char	**tmp;
	int		i;
	int		j;

	len_new_cmd = 0;
	i = -1;
	while (cmd[++i])
	{
		tmp = expand_variable(cmd[i], shell);
		j = 0;
		if (tmp != NULL)
			while (tmp[j++])
				len_new_cmd++;
		ft_free_tab(tmp);
	}
	return (len_new_cmd);
}

void	new_cmd_expand(char ***cmd, t_minishell *shell)
{
	char	**new_cmd;
	int		i;
	int		j;
	int		tets;
	char	**tmp;

	i = -1;
	new_cmd = malloc(sizeof(char *) * (ft_had_len_of_new_tab(shell, *cmd) + 1));
	if (!new_cmd)
		return ;
	i = -1;
	j = 0;
	while ((*cmd)[++i])
	{
		tets = 0;
		tmp = expand_variable((*cmd)[i], shell);
		if ((tmp[0] != NULL && ft_strcmp(tmp[0], "") != 0)
			|| ft_strncmp((*cmd)[i], "$", 1) != 0)
			while (tmp[tets])
				new_cmd[j++] = ft_strdup(tmp[tets++]);
		ft_free_tab(tmp);
	}
	new_cmd[j] = NULL;
	ft_free_tab((*cmd));
	(*cmd) = new_cmd;
}
