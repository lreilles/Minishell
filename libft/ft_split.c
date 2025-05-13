/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:42:32 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/13 06:18:59 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	est_dans_charset(char const c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*copier_mot(char const *str, int debut, int fin)
{
	char	*mot;
	int		i;

	mot = malloc((fin - debut + 1) * sizeof(char));
	if (!mot)
		return (NULL);
	i = 0;
	while (debut < fin)
	{
		mot[i++] = str[debut++];
	}
	mot[i] = '\0';
	return (mot);
}

static void	*free_tableau(char **tab, int k)
{
	while (k > 0)
		free(tab[--k]);
	free(tab);
	return (NULL);
}

static char	**allouer_add_tab(char const *str, char *c, int nb_mot, char **tab)
{
	int	i;
	int	k;
	int	debut;

	i = 0;
	k = 0;
	while (str[i] && k < nb_mot)
	{
		while (str[i] && est_dans_charset(str[i], c))
			i++;
		debut = i;
		while (str[i] && !est_dans_charset(str[i], c))
			i++;
		if (i > debut)
		{
			tab[k] = copier_mot(str, debut, i);
			if (!tab[k])
				return (free_tableau(tab, k));
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char const *str, char charset)
{
	int		nb_mots;
	char	tmp[2];
	char	**tableau;
	int		i;

	tmp[0] = charset;
	tmp[1] = '\0';
	i = 0;
	nb_mots = 0;
	while (str[i])
	{
		if (!est_dans_charset(str[i], tmp))
		{
			if (i == 0 || est_dans_charset(str[i - 1], tmp))
				nb_mots++;
		}
		i++;
	}
	tableau = malloc((nb_mots + 1) * sizeof(char *));
	if (!tableau)
		return (NULL);
	return (allouer_add_tab(str, tmp, nb_mots, tableau));
}
