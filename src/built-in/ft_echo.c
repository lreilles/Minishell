/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 02:39:26 by ameduboi          #+#    #+#             */
/*   Updated: 2025/04/29 22:05:10 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_echo(char **str, int flag)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i != 0)
			ft_printf(" ");
		ft_printf("%s", str[i]);
		i++;
	}
	if (flag == 0)
		ft_printf("\n");
}
