/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:31:10 by ameduboi          #+#    #+#             */
/*   Updated: 2025/04/11 02:03:27 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(char *tab)
{
	int	i;
	int	exit_code;

	i = 0;
	exit_code = 2;
	while (tab[i])
	{
		if (ft_isdigit(tab[i]) == 0)
		{
			free(tab);
			exit(exit_code);
		}
		i++;
	}
	exit_code = ft_atoi(tab);
	free(tab);
	ft_printf("%s\n", "exit");
	exit(exit_code);
}
