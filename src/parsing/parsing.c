/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:25:44 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/11 02:49:24 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parsing(t_minishell *shell, char *line)
{
	char		**args;

	if (!is_quote_closed(line))
		return (shell->exit_status = 2, ft_dprintf(2,
				"minishell: syntax error: unclosed quotes\n"), 0);
	args = ft_split_minishell(line);
	shell->nb_args = count_tab_len(line);
	if (verif_error(args, shell, line))
		return (ft_free_tab(args), 0);
	shell->args = args;
	shell->cmds = creat_cmds(shell);
	shell->cmds = ft_heredoc(shell);
	if (shell->cmds == NULL)
		return (ft_free_tab(args), 0);
	return (1);
}

int	is_quote_closed(const char *line)
{
	int	i;
	int	inside_double_quote;
	int	inside_single_quote;

	inside_double_quote = 0;
	inside_single_quote = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\\' && line[i + 1])
			i++;
		else if (line[i] == '"' && !inside_single_quote)
			inside_double_quote = !inside_double_quote;
		else if (line[i] == '\'' && !inside_double_quote)
			inside_single_quote = !inside_single_quote;
		i++;
	}
	return (inside_double_quote == 0 && inside_single_quote == 0);
}
