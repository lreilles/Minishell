/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 02:03:12 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/12 18:27:04 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_env_value(t_minishell *shell, char **env, char *str, int *i)
{
	int		k;
	int		j;
	char	*value;

	k = 0;
	if (str[0] == '?')
		return ((*i)++, ft_itoa(shell->exit_status));
	while (str[k] && !ft_isspecial_char(str[k], 1))
	{
		k++;
		(*i)++;
	}
	value = ft_substr(str, 0, k);
	if (value[0] == '\0' || value[0] == '$')
		return (free(value), ft_strdup(""));
	j = -1;
	while (env[++j])
	{
		if (ft_strncmp(env[j], value, ft_strlen(value)) == 0)
		{
			if (env[j][ft_strlen(value)] == '=')
				return (free(value), ft_strdup(env[j] + k + 1));
		}
	}
	return (free(value), ft_strdup(""));
}

char	*ft_strjoin_char(char *str, char c)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!str)
	{
		new_str = malloc(sizeof(char) * 2);
		new_str[0] = c;
		new_str[1] = '\0';
		return (new_str);
	}
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);
	return (new_str);
}

char	*expand_in_quote(char *expanded_str, char *str, int *i,
		t_minishell *shell)
{
	char	*value;
	char	*tmp;

	(*i)++;
	if (str[(*i) - 1] == '\"')
	{
		while (str[(*i)] && str[(*i)++] != '"')
		{
			if (str[(*i) - 1] == '$' && !ft_isspecial_char(str[(*i)], 1))
			{
				tmp = expanded_str;
				value = get_env_value(shell, shell->env, str + (*i), i);
				expanded_str = ft_strjoin_check(tmp, value);
				free(tmp);
				free(value);
			}
			else
				expanded_str = ft_strjoin_char(expanded_str, str[(*i) - 1]);
		}
	}
	else
		while (str[(*i)++] != '\'' && str[(*i)])
			expanded_str = ft_strjoin_char(expanded_str, str[(*i) - 1]);
	return (expanded_str);
}

char	*get_home(t_minishell *shell)
{
	char	*home;
	char	*tmp;
	int		i;

	i = 0;
	home = get_env_value(shell, shell->env, "HOME", &i);
	if (home[0] == '\0')
	{
		free(home);
		tmp = get_env_value(shell, shell->env, "LOGNAME", &i);
		if (tmp[0] != '\0')
			return (free(tmp), ft_strdup(""));
		home = ft_strjoin("/home/", tmp);
		free(tmp);
	}
	return (home);
}

char	**expand_variable(char *str, t_minishell *shell)
{
	char	**expanded_tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!have_lentabexpand(str, shell))
		return (NULL);
	expanded_tab = malloc(sizeof(char *) * (have_lentabexpand(str, shell) + 1));
	expanded_tab[have_lentabexpand(str, shell)] = NULL;
	if (ft_strcmp(str, "~") == 0)
		return (expanded_tab[0] = get_home(shell), expanded_tab);
	expanded_tab[j] = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			expanded_tab[j] = expand_in_quote(expanded_tab[j], str, &i, shell);
		else if (str[i] == '$' && (!ft_isspecial_char(str[i + 1], 0)))
			add_to_expanded_tab(shell, str, ((int *[]){&i, &j}), expanded_tab);
		else if (str[i++] != '\\')
			expanded_tab[j] = ft_strjoin_char(expanded_tab[j], str[i - 1]);
		else
			expanded_tab[j] = ft_strjoin_char(expanded_tab[j], str[(i)++]);
	}
	return (expanded_tab);
}
