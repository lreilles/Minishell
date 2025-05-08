/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 03:45:32 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/07 07:57:14 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**get_env_value2(t_minishell *shell, char **env, char *str, int *i)
{
	char	*tmp;
	char	**tmp2;

	tmp = get_env_value(shell, env, str, i);
	tmp2 = ft_split(tmp, ' ');
	free(tmp);
	return (tmp2);
}

int	have_len_tab_expand(char *str, t_minishell *shell)
{
	int		len;
	int		i;
	char	**tmp;
	int		k;

	i = 0;
	len = 1;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			skip_quotes(str, &i, str[i]);
		else if (str[i] == '$')
		{
			tmp = get_env_value2(shell, shell->env, str + i + 1, &i);
			k = 0;
			if (ft_tablen(tmp) > 1)
				while (tmp[(k++) + 1])
					len++;
			ft_free_tab(tmp);
		}
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
