/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 02:03:12 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/11 06:09:49 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_env_value(char **env, char *str, int *i)
{
	int		k;
	int		j;
	char	*value;

	k = 0;
	while (str[k] && str[k] != '$' && str[k] != '\'' && str[k] != '\"')
	{
		k++;
		(*i)++;
	}
	value = ft_substr(str, 0, k);
	j = 0;
	while (env[j])
	{
		if (ft_strncmp(env[j], value, ft_strlen(value)) == 0)
			return (free(value), ft_strdup(env[j] + k + 1));
		j++;
	}
	return (free(value), NULL);
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

char	*expand_in_quote(char *expanded_str, char *str, int *i, char **env)
{
	char	*value;
	char	*tmp;

	if (str[*i] == '\"')
	{
		(*i)++;
		while (str[*i] && str[*i] != '"')
		{
			if (str[*i] == '$')
			{
				tmp = expanded_str;
				value = get_env_value(env, str + *i + 1, i);
				expanded_str = ft_strjoin(tmp, value);
				free(tmp);
				free(value);
			}
			else
				expanded_str = ft_strjoin_char(expanded_str, str[*i]);
			(*i)++;
		}
	}
	else
		while (str[++(*i)] != '\'' && str[(*i)])
			expanded_str = ft_strjoin_char(expanded_str, str[(*i)]);
	return (expanded_str);
}

char	*expand_variable(char *str, char **env)
{
	char	*expanded_str;
	int		i;
	char	*tmp;
	char	*value;

	i = 0;
	expanded_str = ft_strjoin_char(NULL, '\0');
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			expanded_str = expand_in_quote(expanded_str, str, &i, env);
		else if (str[i] == '$')
		{
			tmp = expanded_str;
			value = get_env_value(env, str + i + 1, &i);
			expanded_str = ft_strjoin(tmp, value);
			free(tmp);
			free(value);
		}
		else
			expanded_str = ft_strjoin_char(expanded_str, str[i]);
		i++;
	}
	return (expanded_str);
}

// int	main(int ac, char **av, char **env)
// {
// 	char	*str;

// 	(void)ac;
// 	(void)av;
// 	str = expand_variable("\"$USER\"\'$USER\'\"\'\"\'\"\'", env);
// 	ft_printf("expanded = %s\n", str);
// 	free(str);
// }
