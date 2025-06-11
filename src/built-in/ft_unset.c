/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <ameduboi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:47:17 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/11 04:13:47 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_unset(t_minishell *shell, char **unset)
{
	char	*value;
	int		temp;
	char	*before_equals;

	while (*unset)
	{
		temp = 0;
		before_equals = before_equal(*unset);
		value = get_env_value(shell, shell->env, *unset, &temp);
		if (isinenv(shell, before_equals, value))
			ft_tabdel(&(shell->env), before_equals);
		free(before_equals);
		free(value);
		unset++;
	}
}
