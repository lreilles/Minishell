/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:01:55 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/01 00:33:04 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_struct(t_minishell **shell, char **env)
{
	*shell = malloc(sizeof(t_minishell));
	(*shell)->env = ft_tabdup(env);
	(*shell)->exit_status = 0;
}

int	free_struct(t_minishell *shell)
{
	int	exit_status;

	exit_status = shell->exit_status;
	rl_clear_history();
	ft_free_tab(shell->env);
	free(shell);
	return (exit_status);
}
