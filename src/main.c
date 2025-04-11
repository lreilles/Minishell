/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:08:35 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/11 05:57:01 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av)
{
	t_minishell	*shell;

	(void)ac;
	(void)av;
	signals(SIGNAL_IGN);
	rl_outstream = stderr;
	init_struct(&shell, av + ac + 1);
	minishell(shell);
	close_fds();
	return (free_struct(shell));
}
