/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 22:36:32 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/09 19:00:33 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	found_error(char *export, int j)
{
	int	i;

	i = 0;
	if (export[0] == '=')
	{
		if (j == 1)
			ft_dprintf(2, "minishell: export: '%s': not a valid "
				"identifier\n", export);
		return (1);
	}
	else if (ft_isdigit(export[i]) == 1)
	{
		if (j == 1)
			ft_dprintf(2, "minishell: export: '%s': not a valid "
				"identifier\n", export);
		return (1);
	}
	if (have_equal(export) == 0)
		return (1);
	return (0);
}

int	have_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	isinenv(t_minishell *shell, char *name, char *result)
{
	int	i;

	i = 0;
	if (ft_strcmp(result, "") != 0)
		return (1);
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], name, ft_strlen(name)) == 0
			&& shell->env[i][ft_strlen(name)] == '=')
			return (1);
		i++;
	}
	return (0);
}
