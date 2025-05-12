/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_minishell2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 05:27:54 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/12 18:33:59 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	est_dans_charset(char c)
{
	if (ft_isspace(c) || c == '\'' || c == '\"' || c == '|' || c == '>'
		|| c == '<' || c == '&')
		return (1);
	return (0);
}

int	ft_is_separator(char c)
{
	return (ft_isspace(c) || c == '|' || c == '<' || c == '>' || c == '&');
}

int	ft_is_quote(char c)
{
	return (c == '"' || c == '\'');
}

void	skip_quotes(char *line, int *i, char quote)
{
	while (line[++(*i)] && line[*i] != quote)
		;
	(*i)++;
}

void	increment_if_necessary(int *len, int *add_len)
{
	if (*add_len)
	{
		(*len)++;
		*add_len = 0;
	}
}
