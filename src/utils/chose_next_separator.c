/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_next_separator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 07:30:05 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/09 04:30:19 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	*have_static_int(int nbr)
{
	static int	i;

	if (nbr == 0)
		i = 0;
	return (&i);
}

int	next_separator(char **args)
{
	int	*i;

	i = have_static_int(1);
	while (args[(*i)])
	{
		if (ft_strcmp(args[(*i)], "|") == 0)
			return ((*i)++, 1);
		else if (ft_strcmp(args[(*i)], "||") == 0)
			return ((*i)++, 2);
		else if (ft_strcmp(args[(*i)], "&&") == 0)
			return ((*i)++, 3);
		(*i)++;
	}
	return (0);
}

void	ft_chose_next_separator_pipe(t_command *cmd, t_minishell *shell,
		int or_and)
{
	int	separator;

	separator = next_separator(shell->args);
	if (separator == 1)
		ft_execute_pipe(cmd, shell, or_and);
	else if (separator == 2)
		ft_execute_or(cmd, shell, or_and, 1);
	else if (separator == 3)
		ft_execute_and(cmd, shell, or_and, 1);
	else
		ft_execute_lastcmd_pipe(cmd, shell);
}

void	ft_chose_next_separator(t_command *cmd, t_minishell *shell, int or_and)
{
	int	separator;

	separator = next_separator(shell->args);
	if (separator == 1)
		ft_execute_pipe(cmd, shell, or_and);
	else if (separator == 2)
		ft_execute_or(cmd, shell, or_and, 0);
	else if (separator == 3)
		ft_execute_and(cmd, shell, or_and, 0);
	else
		ft_execute_lastcmd(cmd, shell, or_and);
}
