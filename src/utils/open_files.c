/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 03:46:24 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/11 02:55:15 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	acess_file(t_minishell *shell, char *file, int flags)
{
	int	fd;

	if (flags == 1)
	{
		if (access(file, F_OK) == -1)
			return (shell->exit_status = 1, ft_dprintf(2, "minishell: "
					"%s: No such file or directory\n", file), -1);
		fd = open(file, O_RDONLY, 0644);
	}
	else if (flags == 3)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (flags == 4)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return (-1);
	if (fd == -1)
		return (shell->exit_status = 1, ft_dprintf(2, "minishell: %s: "
				"Permission denied\n", file), -1);
	return (fd);
}
