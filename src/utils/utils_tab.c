/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:00:44 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/07 22:31:12 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_tabdup(char **tab)
{
	char	**res;
	int		i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		i++;
	res = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (tab != NULL && tab[i] != NULL)
	{
		i[res] = ft_strdup(tab[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (i[tab])
	{
		free(i[tab]);
		i++;
	}
	free(tab);
}

int	ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void	ft_tabdel(char ***tab, char *value)
{
	int		i;
	int		j;
	char	**new_tab;

	j = ft_tablen(*tab) - 1;
	new_tab = malloc(sizeof(char *) * (j + 1));
	if (!new_tab)
		return ;
	new_tab[j] = NULL;
	i = 0;
	j = 0;
	while ((*tab)[i])
	{
		if (ft_strncmp((*tab)[i], value, ft_strlen(value)) == 0
			&& (*tab)[i][ft_strlen(value)] == '=')
			free((*tab)[i]);
		else
			new_tab[j++] = (*tab)[i];
		i++;
	}
	i = 0;
	free(*tab);
	*tab = new_tab;
}
