/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:25:44 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/06 03:46:17 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	parsing(t_minishell *shell, char *line)
{
	char	**args;
	int		i;

	i = 0;
	args = ft_split_minishell(line);
	if (!is_quote_closed(line))
		return (shell->exit_status = 2, (void)ft_dprintf(2,
				"minishell: syntax error: unclosed quotes\n"));
	args = ft_split_minishell(line);
	// shell->nb_args = count_args(args);
	// while (args[i])
	// {
	// 	if (ft_strcmp(args[i], "|") == 0)
	// 	{
	// 		if (i == 0 || i == shell->nb_args - 1 || ft_strcmp(args[i + 1],
	// 				"|") == 0)
	// 			return (shell->exit_status = 2, (void)ft_dprintf(2,
	// 					"minishell: syntax error near unexpected token `|'\n"));
	// 	}
	// 	i++;
	// }
	// ft_free_tab(args);
	(void)shell;
	(void)line;
}
// char	**remove_quotes(char **args)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (args[i])
// 	{
// 		j = 0;
// 		while (args[i][j])
// 		{
// 			if (args[i][j] == '\'' || args[i][j] == '\"')
// 			{
// 				args[i][j] = '\0';
// 				break ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (args);
// }

int	is_quote_closed(const char *line)
{
	int	inside_double_quote;
	int	inside_single_quote;

	inside_double_quote = 0;
	inside_single_quote = 0;
	while (*line)
	{
		if (*line == '"' && !inside_single_quote)
			inside_double_quote = !inside_double_quote;
		else if (*line == '\'' && !inside_double_quote)
			inside_single_quote = !inside_single_quote;
		line++;
	}
	return (inside_double_quote == 0 && inside_single_quote == 0);
}
