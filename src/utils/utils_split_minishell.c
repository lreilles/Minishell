/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_minishell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:52:51 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/06 04:50:37 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
				return (ft_free_tab(tab), NULL);
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
		if (!est_dans_charset(str[i], &charset))
		{
			if (i == 0 || est_dans_charset(str[i - 1], &charset))
				nb_mots++;
		}
		i++;
	}
	tableau = malloc((nb_mots + 1) * sizeof(char *));
	if (!tableau)
		return (NULL);
	return (allouer_add_tab(str, tmp, nb_mots, tableau));
}

int	tab_len(char *line)
{
	int	i;
	int	len;
	int	quote;

	len = 1;
	i = 0;
	quote = 0;
	while (ft_isspace(line[i]))
		i++;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			quote = line[i];
			i++;
			while (line[i] != quote && line[i])
				i++;
			while (ft_isspace(line[i]))
				i++;
		}
		else if (line[i] == '|' || line[i] == '&' || line[i] == ' ')
		{
			len++;
			if (line[i] == '|' || line[i] == '&')
			{
				len++;
				i++;
			}
			if (line[i] == '|' || line[i] == '&')
				i++;
			// i++;
			while (ft_isspace(line[i]))
				i++;
		}
		else
		{
			while (line[i] != ' ' && line[i] != '|' && line[i] != '&'
				&& line[i] != '\0')
				i++;
			if (ft_isspace(line[i] || line[i] == '|' || line[i] == '&'))
				len++;
			while (ft_isspace(line[i]))
				i++;
		}
	}
	return (len);
}

char	**ft_split_minishell(char *line)
{
	int	i;
	int	j;

	// char	**tab;
	i = 0;
	j = 0;
	ft_printf("%d\n", tab_len(line));
	// tab = malloc(2 * sizeof(char *));
	// while (line[i])
	// {
	// }
	return (NULL);
}
