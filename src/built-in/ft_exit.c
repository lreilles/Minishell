/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:31:10 by ameduboi          #+#    #+#             */
/*   Updated: 2025/04/11 00:56:41 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(char *tab)
{
	int	i;
	int	exit_code;

	i = 0;
	exit_code = 0;





	free(tab);
	ft_printf("%s\n", "exit");
	exit(exit_code);
//	if (tab[tab_of_len(tab)] != 1)
//	{
//		ft_dprintf(2, "exit : too many arguments\n");
//		return ;
//	}

}
