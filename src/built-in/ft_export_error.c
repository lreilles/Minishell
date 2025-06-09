/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <ameduboi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 22:36:32 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/09 00:28:08 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	found_error(t_minishell *shell, char *export, int j)
{
	int	i;

	i = 0;
	if (export[0] == '=')
	{
		if (j == 1)
			ft_dprintf(2, "minishell: export: '%s': not a valid "
					"identifier\n", export);
		return (1);
	}
	else if (ft_isdigit(export[i]) == 1)
	{
		if (j == 1)
			ft_dprintf(2, "minishell: export: '%i': not a valid "
					"identifier\n", shell->exit_status);
		return (1);
	}
	if (have_equal(export) == 0)
                return (1);
	return (0);
}
