/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <ameduboi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 02:39:26 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/12 01:40:26 by ameduboi         ###   ########.fr       */
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
		{
			verif = ft_printf(" ");
			if (verif < 0)
				return (1);
		}
		verif = ft_printf("%s", str[i]);
		if (verif < 0)
			return (1);
		i++;
	}
	if (flag == 0)
	{
		verif = ft_printf("\n");
		if (verif < 0)
			return (1);
	}
	return (0);
}
