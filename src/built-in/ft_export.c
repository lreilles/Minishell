/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:21:44 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/09 19:12:48 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*before_equal(char *value)
{
	int		i;
	char	*result;

	i = 0;
	while (value[i] != '=' && value[i])
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
	while (value[i] != '=' && value[i])
		i++;
	if (!value[i])
		return (ft_strdup(""));
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
	char	*res;
	char	*first;
	int		temp;
	int		i;
	char	*end;

	i = -1;
	while (export[++i])
	{
		temp = 0;
		first = before_equal(export[i]);
		res = get_env_value(shell, shell->env, first, &temp);
		if (!found_error(export[i], 1) && isinenv(shell, first, res))
		{
			end = after_equal(export[i]);
			edit_env_value(shell, first, end);
			free(end);
		}
		else if (!found_error(export[i], 0))
			ft_export_with_value(shell, export[i]);
		free(first);
		free(res);
	}
	return (0);
}
