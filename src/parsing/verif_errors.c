/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 02:34:54 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/10 06:42:33 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_isspecial(int i, char *str)
{
	if (i == 0)
		return (1);
	if (!ft_strcmp(str, "|") || !ft_strcmp(str, "||") || !ft_strcmp(str, "&&")
		|| !ft_strcmp(str, "<") || !ft_strcmp(str, ">") || !ft_strcmp(str, "<<")
		|| !ft_strcmp(str, ">>"))
		return (1);
	return (0);
}

int	ft_isspecial_or_0(int i, char **tab)
{
	if (i == 0)
		return (1);
	return (ft_isspecial(i, tab[i - 1]));
}

int	msg_error_for_syntax(char *str, int i, t_minishell *shell)
{
	if (shell->nb_args - 1 == i)
		return (shell->exit_status = 2, ft_dprintf(2,
				"minishell: syntax error"
				" near unexpected token `newline'\n"));
	else
		return (shell->exit_status = 2, ft_dprintf(2,
				"minishell: syntax error near unexpected"
				" token `%s'\n", str));
}

int	verif_special_char(char **tab, t_minishell *shell)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], "|") || !ft_strcmp(tab[i], "||")
			|| !ft_strcmp(tab[i], "&&"))
			if (i == shell->nb_args - 1 || ft_isspecial_or_0(i, tab))
				return (shell->exit_status = 2, ft_dprintf(2,
						"minishell: syntax error near unexpected token `%s'\n",
						tab[i]));
		if (!ft_strcmp(tab[i], "<") || !ft_strcmp(tab[i], ">")
			|| !ft_strcmp(tab[i], "<<") || !ft_strcmp(tab[i], ">>"))
		{
			if (i == shell->nb_args - 1 || ft_isspecial(i + 1, tab[i + 1]))
				return (msg_error_for_syntax(tab[i + 1], i, shell));
		}
		i++;
	}
	return (0);
}

int	verif_error(char **tab, t_minishell *shell, char *line)
{
	(void)(line);
	if (verif_special_char(tab, shell))
		return (1);
	return (0);
}
