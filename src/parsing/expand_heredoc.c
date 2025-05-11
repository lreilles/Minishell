/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 01:42:59 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/11 03:32:30 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_expand_heredoc(t_minishell *shell, char *str)
{
	char	*expanded_str;
	int		i;
	char	*tmp;
	char	*value;

	i = 0;
	expanded_str = NULL;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$')
		{
			tmp = expanded_str;
			value = get_env_value(shell, shell->env, str + i++ + 1, &i);
			expanded_str = ft_strjoin_check(tmp, value);
			free(tmp);
			free(value);
		}
		else
			expanded_str = ft_strjoin_char(expanded_str, str[i++]);
	}
	return (expanded_str);
}
