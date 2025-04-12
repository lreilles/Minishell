/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:25:44 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/12 00:17:04 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parsing(t_minishell *shell, char *line)
{
	char		**args;
	t_command	*test;
	int			i;

	if (!is_quote_closed(line))
		return (shell->exit_status = 2, ft_dprintf(2,
				"minishell: syntax error: unclosed quotes\n"), 0);
	args = ft_split_minishell(line);
	shell->nb_args = count_tab_len(line);
	if (verif_error(args, shell, line))
		return (ft_free_tab(args), 0);
	shell->args = args;
	shell->cmds = creat_cmds(shell);
	shell->cmds = redirection(shell);
	if (shell->cmds == NULL)
		return (ft_free_tab(args), 0);
	test = shell->cmds;
	while (test)
	{
		i = 0;
		while (test->cmd[i])
			ft_printf("cmd without redir = %s\n", shell->cmds->cmd[i++]);
		test = test->next;
	}
	return (1);
}

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
