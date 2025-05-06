/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 02:39:26 by ameduboi          #+#    #+#             */
/*   Updated: 2025/05/06 00:18:04 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_echo(char **str, int flag)
{
	int	i;
	int	verif;

	i = 0;
	while (str[i])
	{
		if (i != 0)
			ft_printf(" ");
		verif = ft_printf("%s", str[i]);
		if (verif < 0)
			return (1)
		i++;
	}
	if (flag == 0)
		ft_printf("\n");
	return (0);
}
