/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:08:35 by lsellier          #+#    #+#             */
/*   Updated: 2025/03/31 21:58:25 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_tabdup(char **tab)
{
	char	**res;
	int		i;

	i = 0;
	if (!tab || !tab[0])
		return (NULL);
	while (tab[i])
		i++;
	res = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (tab != NULL && tab[i] != NULL)
	{
		res[i] = ft_strdup(tab[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

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

int	main(int ac, char **av)
{
	t_minishell	*shell;

	(void)ac;
	(void)av;
	signals(SIGNAL_IGN);
	rl_outstream = stderr;
	init_struct(&shell, av + ac + 1);
	minishell(shell);
	return (free_struct(shell));
}
