/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:31:25 by ameduboi          #+#    #+#             */
/*   Updated: 2025/04/02 22:47:58 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	pwd(char **env)
{
	int	i;
	char *oldpwd;

	i = 0;
	while (env[i] && ft_strncmp("OLDPWD=", env[i], 7) != 0)
		i++;
	while (env[i] != NULL)
	{
		ft_printf("%s", env[i]);
		i++;
	}
	ft_printf("\n");
}
//    OLDPWD=/home/ameduboi/Documents/42cursus/3rd_circle/Minishell/src/built-in
