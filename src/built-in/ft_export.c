/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:21:44 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/06 12:58:19 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*before_equal(char *value)
{
	int		i;
	char	*result;

	i = 0;
	while (value[i] != '=')
		i++;
	result = malloc(sizeof(char) * (i + 2));
	ft_strlcpy(result, value, i + 1);
	return (result);
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

void	ft_export_with_value(t_minishell *shell, char *export)
{
	int		i;
	int		j;
	char	**new_env;

	i = ft_tablen(shell->env) + 1;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return ;
	j = -1;
	while (shell->env[++j])
		new_env[j] = shell->env[j];
	new_env[i - 1] = ft_strdup(export);
	new_env[i] = NULL;
	free(shell->env);
	shell->env = new_env;
}

int	ft_export(t_minishell *shell, char **export)
{
	char	*result;
	char	*first_value;
	int		temp;
	int		i;
	char	*end_value;

	i = 0;
	while (export[i])
	{
		temp = 0;
		first_value = before_equal(export[i]);
		result = get_env_value(shell, shell->env, first_value, &temp);
		if (ft_strcmp(result, "") != 0)
		{
			end_value = after_equal(export[i]);
			edit_env_value(shell, first_value, end_value);
			free(end_value);
		}
		else
			ft_export_with_value(shell, export[i]);
		free(first_value);
		free(result);
		i++;
	}
	return (0);
}
