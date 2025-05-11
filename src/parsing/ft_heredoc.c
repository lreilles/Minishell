/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 00:49:38 by lsellier          #+#    #+#             */
/*   Updated: 2025/05/11 04:44:18 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	have_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_quote(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	loop_heredoc(t_minishell *shell, char *eof, int fd)
{
	char	*line;
	int		line_error;
	int		expand;

	line_error = 0;
	expand = !have_quote(eof);
	rl_clear_history();
	while (++line_error)
	{
		signals(SIGNAL_HERE_DOC);
		line = readline("> ");
		signals(SIGNAL_IGN);
		add_history(line);
		if (line && expand && line[0])
			line = ft_expand_heredoc(shell, line);
		if (line == NULL)
			break ;
		if (ft_strcmp(line, eof) == 0)
			return ((void)free(line));
		ft_dprintf(fd, "%s\n", line);
		free(line);
	}
	ft_dprintf(2, "minishell: warning: here-document at line %i "
		"delimited by end-of-file (wanted `%s')\n", line_error, eof);
}

void	open_and_loop_heredoc(t_minishell *shell, t_command **cmd,
		char	*tmp_file, int *i)
{
	int		fd;
	char	*tmp;

	fd = open(tmp_file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	tmp = ft_strdup((*cmd)->cmd[(*i) + 1]);
	free(tmp_file);
	if (fd == -1)
	{
		ft_dprintf(2, "minishell: error open tmp heredoc\n");
		ft_free_before_exit(shell, 0, fd);
		close_fds(0);
		free(tmp);
		exit(1);
	}
	loop_heredoc(shell, tmp, fd);
	ft_free_before_exit(shell, 0, fd);
	free(tmp);
	close_fds(0);
	exit(g_sig);
}

void	ft_create_heredoc(t_minishell *shell, t_command **cmd, int *i, int n)
{
	char	*str;
	int		status;

	(*cmd)->pid = fork();
	if ((*cmd)->pid == -1)
		return (g_sig = 130, (void)ft_dprintf(2, "minishell: error "
				"fork failed heredoc\n"));
	str = have_tmp_file(n);
	if ((*cmd)->pid == 0)
		open_and_loop_heredoc(shell, cmd, str, i);
	waitpid((*cmd)->pid, &status, 0);
	status = WEXITSTATUS(status);
	if (status == 0)
	{
		free((*cmd)->cmd[(*i) + 1]);
		(*cmd)->cmd[(*i) + 1] = str;
	}
	else
	{
		g_sig = 130;
		free(str);
	}
}

t_command	*ft_heredoc(t_minishell *shell)
{
	t_command	*cmd;
	int			i;
	int			nbr_heredoc;

	if (!shell->cmds)
		return (NULL);
	nbr_heredoc = 0;
	cmd = shell->cmds;
	while (cmd)
	{
		i = 0;
		while (cmd->cmd[i])
		{
			if (ft_strcmp(cmd->cmd[i], "<<") == 0)
				ft_create_heredoc(shell, &cmd, &i, nbr_heredoc++);
			if (g_sig == 130)
				return (ft_free_t_command(shell), NULL);
			i++;
		}
		cmd = cmd->next;
	}
	shell->nbr_file = nbr_heredoc;
	return (shell->cmds);
}
