/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:02:49 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/14 02:39:37 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_fds(t_lst_int **fd_list)
{
	t_lst_int	*tmp;

	if (!(*fd_list))
		return ;
	while ((*fd_list))
	{
		tmp = (*fd_list);
		(*fd_list) = (*fd_list)->next;
		if (tmp->nbr != 0 && tmp->nbr != 1 && tmp->nbr != 2)
			close(tmp->nbr);
		free(tmp);
	}
	(*fd_list) = NULL;
}

void	close_fds_without(t_lst_int **fd_list, int fd_in, int fd_out)
{
	t_lst_int	*tmp;

	while ((*fd_list))
	{
		if (!((*fd_list)->nbr == fd_in || (*fd_list)->nbr == fd_out
				|| (*fd_list)->nbr == 2))
			close((*fd_list)->nbr);
		tmp = (*fd_list);
		(*fd_list) = (*fd_list)->next;
		free(tmp);
	}
	(*fd_list) = NULL;
}
