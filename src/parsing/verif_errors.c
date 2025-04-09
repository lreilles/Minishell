/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 02:34:54 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/09 05:17:29 by lsellier         ###   ########.fr       */
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

int	verif_special_char(char **tab, t_minishell *shell)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], "|") || !ft_strcmp(tab[i], "||")
			|| !ft_strcmp(tab[i], "&&"))
		{
			if (i == shell->nb_args - 1 || ft_isspecial(i, tab[i - 1]))
				return (shell->exit_status = 2, ft_dprintf(2,
						"minishell: syntax error near unexpected token `%s'\n",
						tab[i]));
		}
		if (!ft_strcmp(tab[i], "<") || !ft_strcmp(tab[i], ">")
			|| !ft_strcmp(tab[i], "<<") || !ft_strcmp(tab[i], ">>"))
			if (i == shell->nb_args - 1)
				return (shell->exit_status = 2,
					ft_dprintf(2, "minishell: syntax error"
						" near unexpected token `newline'\n"));
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
