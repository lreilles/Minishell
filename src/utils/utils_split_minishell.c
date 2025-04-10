/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_minishell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:52:51 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/10 23:42:47 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	separator_count(char *line, int *i, int *len, int *add_len)
{
	char	special;
	int		count;

	special = line[*i];
	count = 0;
	if (ft_isspace(special))
	{
		*add_len = 1;
		while (ft_isspace(line[*i]))
			(*i)++;
	}
	else
	{
		while (line[*i] == special && count < 2)
		{
			(*i)++;
			count++;
		}
		(*len)++;
		(*add_len) = 1;
	}
}

int	count_tab_len(char *line)
{
	int	i;
	int	len;
	int	add_len;

	len = 0;
	i = 0;
	add_len = 1;
	while (line[i])
	{
		if (!est_dans_charset(line[i]))
		{
			while (line[i] && !est_dans_charset(line[i]))
				i++;
			increment_if_necessary(&len, &add_len);
		}
		else if (line[i] == '"' || line[i] == '\'')
		{
			increment_if_necessary(&len, &add_len);
			skip_quotes(line, &i, line[i]);
		}
		else if (ft_is_separator(line[i]))
			separator_count(line, &i, &len, &add_len);
	}
	return (len);
}

int	len_of_str_split(char *line)
{
	int		len;
	char	special;

	len = 0;
	if (line[len] == '|' || line[len] == '&' || line[len] == '<'
		|| line[len] == '>')
	{
		special = line[len];
		while (line[len] == special && len < 2)
			len++;
	}
	else
	{
		while (line[len] && !ft_isspace(line[len]) && !(line[len] == '|'
				|| (line[len] == '&') || line[len] == '<' || line[len] == '>'))
		{
			if (line[len] == '\"' || line[len] == '\'')
				skip_quotes(line, &len, line[len]);
			else
				len++;
		}
	}
	return (len);
}

void	add_char_to_tab(char **tab, char *line, int len_of_str)
{
	int	i;

	i = 0;
	while (i < len_of_str)
	{
		(*tab)[i] = line[i];
		i++;
	}
	(*tab)[i] = '\0';
}

char	**ft_split_minishell(char *line)
{
	char	**tab;
	int		i;
	int		len_of_str;
	int		len_of_tab;

	i = 0;
	len_of_tab = count_tab_len(line);
	tab = malloc((len_of_tab + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (i != len_of_tab)
	{
		while (ft_isspace(*line))
			line++;
		len_of_str = len_of_str_split(line);
		tab[i] = malloc((len_of_str + 1) * sizeof(char));
		add_char_to_tab(&(tab[i]), line, len_of_str);
		line = line + len_of_str;
		i++;
	}
	tab[len_of_tab] = NULL;
	i = 0;
	return (tab);
}
