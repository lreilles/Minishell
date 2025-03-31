/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:00:44 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/01 00:01:00 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_tabdup(char **tab)
{
	char	**res;
	int		i;

	i = 0;
	if (!tab || !tab[0])
		return (NULL);
	while (tab[i])
		i++;
	res = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (tab != NULL && tab[i] != NULL)
	{
		res[i] = ft_strdup(tab[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
