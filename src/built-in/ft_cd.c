/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <ameduboi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:32:35 by ameduboi          #+#    #+#             */
/*   Updated: 2025/05/13 02:01:04 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cd(t_minishell *minishell, char **cmd)
{
	int			verif;
	const char	*path;
	int			i;

	i = 0;
	while (cmd[i])
	{
		verif = chdir(cmd[i]);
		if (verif < 0)
			return (1);
		i++;
	}
	return (0);
}
