/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   without_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 07:15:48 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/13 07:31:18 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*without_quotes(char *str)
{
	char	*new_str;
	int		i;

	if (str == NULL)
		return (ft_strdup(""));
	i = 0;
	if (str[0] == '"' || str[0] == '\'')
	{
		while (str[++i] != str[0] && str[i])
			;
		new_str = ft_substr(str, 1, i - 1);
	}
	else
		new_str = ft_strdup(str);
	return (new_str);
}
