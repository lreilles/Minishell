/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:02:49 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/04 16:21:05 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_fds(int fd)
{
	while (fd < 1024)
		close(fd++);
}

void	close_fds_without(int fd, int fd_in, int fd_out)
{
	while (fd < 1024)
	{
		if (!(fd == fd_in || fd == fd_out || fd == 2))
			close(fd);
		fd++;
	}
}
