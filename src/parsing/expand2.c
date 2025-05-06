/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:20:47 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/06 01:14:45 by lsellier         ###   ########.fr       */
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

	i = -1;
	len = 1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '"')
			skip_quotes(str, &i, str[i]);
		else if (str[i] == '$')
		{
			tmp = get_env_value2(shell, shell->env, str + i + 1, &i);
			if (ft_tablen(tmp) > 1)
			{
				k = 0;
				while (tmp[(k++) + 1])
					len++;
			}
			ft_free_tab(tmp);
		}
	}
	return (len);
}

void	add_to_expanded_tab(t_minishell *shell, char *str, int *i, int *j,
		char **expanded_tab)
{
	int		k;
	char	*tmp;
	char	**value;

	tmp = expanded_tab[(*j)];
	value = get_env_value2(shell, shell->env, str + (*i) + 1, i);
	if (ft_tablen(value) <= 1)
	{
		expanded_tab[(*j)] = ft_strjoin_check(tmp, value[0]);
		free(tmp);
		ft_free_tab(value);
	}
	else
	{
		k = 0;
		while (value[k + 1])
		{
			expanded_tab[(*j)++] = ft_strjoin_check(tmp, value[k++]);
			free(tmp);
			tmp = ft_strdup("");
		}
		expanded_tab[(*j)] = ft_strjoin_check(tmp, value[k]);
		free(tmp);
		ft_free_tab(value);
	}
}

char	**expand_variable2(char *str, t_minishell *shell)
{
	char	**expanded_tab;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (str == NULL)
		return (NULL);
	if (!have_len_tab_expand(str, shell))
		return (NULL);
	expanded_tab = malloc(sizeof(char *) * (have_len_tab_expand(str, shell)
				+ 1));
	expanded_tab[have_len_tab_expand(str, shell)] = NULL;
	expanded_tab[j] = ft_strdup("");
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '"')
			expanded_tab[j] = expand_in_quote(expanded_tab[j], str, &i, shell);
		else if (str[i] == '$')
			add_to_expanded_tab(shell, str, &i, &j, expanded_tab);
		else
			expanded_tab[j] = ft_strjoin_char(expanded_tab[j], str[i]);
	}
	return (expanded_tab);
}

// int	main(int ac, char **av, char **env)
// {
// 	char		*str;
// 	t_minishell	*shell;
// 	char		**tab;
// 	int			i;

// 	str = "sa$tedsst";
// 	i = 0;
// 	(void)ac;
// 	(void)av;
// 	init_struct(&shell, env);
// 	shell->line = ft_strdup("test");
// 	tab = expand_variable2(str, shell);
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// 	ft_free_tab(tab);
// 	ft_free_before_exit(shell, -1, -1);
// 	return (0);
// }
