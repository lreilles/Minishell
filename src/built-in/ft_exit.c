/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:31:10 by ameduboi          #+#    #+#             */
/*   Updated: 2025/04/11 00:44:27 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(char **tab)
{
	int	i;

	i = 0;
	if (tab[tab_of_len(tab)] != 1)
	{
		ft_dprintf(2, "exit : too many arguments\n");
		return ;
	}

}
