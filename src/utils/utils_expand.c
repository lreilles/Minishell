/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 03:45:32 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/12 18:26:00 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_isspecial_char(char c, int flag)
{
	if (c == '$' || c == '\\'
		|| c == ' ' || c == '~' || c == '`' || c == ';'
		|| c == '|' || c == '&' || c == '(' || c == ')'
		|| c == '{' || c == '}' || c == '[' || c == ']'
		|| c == '<' || c == '>' || c == ':' || c == '='
		|| c == '!' || c == '^' || c == '#' || c == '%'
		|| c == '@' || c == '+' || c == '-' || c == '/'
		|| c == '*' || c == ',' || c == '.')
		return (1);
	if (flag == 1)
		if (c == '\'' || c == '\"')
			return (1);
	return (0);
}

char	**get_env_value2(t_minishell *shell, char **env, char *str, int *i)
{
	char	*tmp;
	char	**tmp2;

	if (*str == '\0' || *str == '\'' || *str == '\"')
	{
		(*i)++;
		if (*str == '\0')
			return (ft_split("$", ' '));
		return (ft_split("", ' '));
	}
	tmp = get_env_value(shell, env, str, i);
	tmp2 = ft_split(tmp, ' ');
	(*i)++;
	free(tmp);
	return (tmp2);
}

void	add_len_of_new_cmd(t_minishell *shell, char *str, int *i, int *len)
{
	int		len_tmp;
	char	**tmp;

	tmp = get_env_value2(shell, shell->env, str + *i + 1, i);
	len_tmp = 0;
	if (ft_tablen(tmp) > 1)
		while (tmp[(len_tmp++) + 1])
			(*len)++;
	ft_free_tab(tmp);
}

int	have_lentabexpand(char *str, t_minishell *shell)
{
	int	len;
	int	i;

	i = 0;
	len = 1;
	if (!str)
		return (0);
	if (ft_strcmp("~", str) == 0)
		return (1);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			skip_quotes(str, &i, str[i]);
		else if (str[i] == '$')
			add_len_of_new_cmd(shell, str, &i, &len);
		else
			i++;
	}
	return (len);
}

void	add_to_expanded_tab(t_minishell *shell, char *str, int *n[2],
		char **expanded_tab)
{
	int		k;
	char	*tmp;
	char	**value;

	tmp = expanded_tab[(*n[1])];
	value = get_env_value2(shell, shell->env, str + (*n[0]) + 1, n[0]);
	if (ft_tablen(value) <= 1)
	{
		expanded_tab[(*n[1])] = ft_strjoin_check(tmp, value[0]);
		free(tmp);
		ft_free_tab(value);
	}
	else
	{
		k = 0;
		while (value[k + 1])
		{
			expanded_tab[(*n[1])++] = ft_strjoin_check(tmp, value[k++]);
			free(tmp);
			tmp = ft_strdup("");
		}
		expanded_tab[(*n[1])] = ft_strjoin_check(tmp, value[k]);
		free(tmp);
		ft_free_tab(value);
	}
}
