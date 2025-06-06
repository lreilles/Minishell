/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:47:17 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/06 12:07:37 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_unset(t_minishell *shell, char **unset)
{
	char	*value;
	int		temp;

	while (*unset)
	{
		temp = 0;
		value = get_env_value(shell, shell->env, *unset, &temp);
		if (ft_strcmp(value, "") != 0)
			ft_tabdel(&(shell->env), *unset);
		free(value);
		unset++;
	}
}
