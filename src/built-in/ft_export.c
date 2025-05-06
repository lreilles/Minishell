/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:21:44 by ameduboi          #+#    #+#             */
/*   Updated: 2025/04/30 22:55:42 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_export(t_minishell *minishell, char **export)
{
	int		i;
	int		j;
	char	**new_env;

	i = ft_tablen(minishell->env) + ft_tablen(export);
	new_env = malloc(i + 1 * sizeof(char *));
	if (!new_env)
		return (NULL);
	i = 0;
	while (minishell->env[i])
	{
		new_env[i] = ft_strdup(minishell->env[i]);
		i++;
	}
	j = 0;
	while (export[i])
		new_env[i++] = ft_strdup(export[j++]);
	new_env[i] = '\0';
	ft_free_tab(minishell->env);
	minishell->env = ft_tabdup(new_env);
}
