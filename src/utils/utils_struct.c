/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:01:55 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/08 02:06:38 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**edit_env_value(t_minishell *shell, char *value, char *new_one)
{
	char	*tmp;
	char	*new_value;
	int		i;

	i = 0;
	if (!shell->env)
		return (NULL);
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], value, ft_strlen(value)))
		{
			tmp = ft_strjoin(value, "=");
			new_value = ft_strjoin(tmp, new_one);
			free(shell->env[i]);
			shell->env[i] = new_value;
			free(tmp);
			break ;
		}
		i++;
	}
	return (shell->env);
}

void	shlvl(t_minishell **shell)
{
	char	*shlvl;
	int		temp;

	temp = 0;
	shlvl = get_env_value(*shell, (*shell)->env, "SHLVL", &temp);
	if (shlvl)
	{
		temp = ft_atoi(shlvl) + 1;
		free(shlvl);
		shlvl = ft_itoa(temp);
		edit_env_value(*shell, "SHLVL", shlvl);
	}
	free(shlvl);
}

void	init_struct(t_minishell **shell, char **env)
{
	*shell = malloc(sizeof(t_minishell));
	(*shell)->env = ft_tabdup(env);
	(*shell)->exit_status = 0;
	(*shell)->exit = 0;
	(*shell)->nb_args = 0;
	(*shell)->args = NULL;
	(*shell)->cmds = NULL;
	(*shell)->pid_list = NULL;
	shlvl(shell);
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

void	ft_free_t_pid(t_pid *pid_list)
{
	t_pid	*tmp;

	while (pid_list)
	{
		tmp = pid_list;
		pid_list = pid_list->next;
		free(tmp);
	}
	pid_list = NULL;
}
