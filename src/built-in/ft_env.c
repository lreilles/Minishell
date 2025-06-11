/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <ameduboi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:48:39 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/12 01:40:25 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env(t_minishell *minishell)
{
	int	i;
	int	verif;

	i = 0;
	while (minishell->env[i] != NULL)
	{
		verif = ft_printf("%s\n", minishell->env[i]);
		if (verif < 0)
			return (1);
		i++;
	}
	return (0);
}
