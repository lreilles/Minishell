/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:21:44 by ameduboi          #+#    #+#             */
/*   Updated: 2025/05/06 18:17:08 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// edit_env_value(t_minishell *shell, char *value, char *new_one)

char	*before_equal(char *value)
{
	int		i;
	char	*result;

	i = 0;
	while (value[i] != '=')
		i++;
	result = malloc(i + 1);
	result = ft_strncpy(result, value, i);
	return(result);
}

char	*after_equal(char *value)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (value[i] != '=')
		i++;
	i++;
	j = ft_strlen(value) - i;
	result = malloc(j + 1);
	j = 0;
	while (value[i] != '\0')
		result[j++] = value[i++];
	result[j] = '\0';
	return (result);
}

void	ft_export(t_minishell *shell, char **export)
{
	char	*result;
	char	*first_value;
	int		i;
	char	*end_value;

	i = 0;
	while (export[i])
	{
		first_value = before_equal(export[i]);
		result = get_env_value(*shell, (*shell)->env, first_value, 0);
		if (result)
		{
			free(result);
			end_value = after_equal(export[i]);
			edit_env_value(*shell, first_value, end_value);
		}
		else
			ft_export_with_value(shell, export[i]);
		i++;
	}
	free(result);
}

void	ft_export_with_value(t_minishell *shell, char *export)
{
	int		i;
	int		j;
	char	**new_env;

	i = ft_tablen(shell->env) + ft_tablen(export);
	new_env = malloc(i + 1 * sizeof(char *));
	if (!new_env)
		return (NULL);
	i = ft_tablen(shell->env) + 1;
	j = 0;
	while (export[j])
	{
		new_env[i][j] = export[j];
		j++;
	}
	new_env[i][j] = '\0';
	ft_free_tab(shell->env);
	shell->env = ft_tabdup(new_env);
}
