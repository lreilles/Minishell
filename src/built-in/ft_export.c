/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:21:44 by ameduboi          #+#    #+#             */
/*   Updated: 2025/04/30 02:36:07 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_export(t_minishell *minishell, char **export)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	while (minishell->env[i])
		minishell->env[i++];
	while (export[j])
		j++;
	new_env = malloc(i + j + 1 * sizeof(char *));
	while ()
	{
		
	}
}
