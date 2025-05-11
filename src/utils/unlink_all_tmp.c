/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_all_tmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 04:10:18 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/11 04:36:37 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*have_tmp_file(int i)
{
	char	*tmp;
	char	*str;

	tmp = ft_itoa(i);
	str = ft_strjoin("/tmp/tmp_", tmp);
	free(tmp);
	return (str);
}

void	unlink_all_tmp(int nbr)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < nbr)
	{
		tmp = have_tmp_file(i);
		unlink(tmp);
		free(tmp);
		i++;
	}
}
