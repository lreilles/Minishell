/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:31:10 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/10 09:06:48 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	verif_overflow(long long int nb, long long int verif, int sign)
{
	if (sign < 0)
		if (nb == LLONG_MIN)
			return (0);
	if (nb < verif)
		return (1);
	return (0);
}

int	can_atoll(const char *str)
{
	long long int	nb;
	int				sign;
	long long int	verif;

	sign = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		verif = nb;
		nb = nb * 10 + (*str - '0');
		if (verif_overflow(nb, verif, sign))
			return (0);
		str++;
	}
	return (1);
}

int	ft_numeric_argument_error(const char *str)
{
	if (ft_strlen(str) > 20)
		return (0);
	if (!can_atoll(str))
		return (0);
	while (*str && *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str != ' ')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	while (*str && *str == ' ')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

int	ft_atoll(const char *str)
{
	int				i;
	long long int	nb;
	int				sign;
	int				res;

	if (*str == '\0')
		return (0);
	i = 0;
	sign = 1;
	nb = 0;
	while ((i[str] >= 9 && i[str] <= 13) || i[str] == ' ')
		i++;
	if (i[str] == '+' || i[str] == '-')
	{
		if (i[str] == '-')
			sign *= -1;
		i++;
	}
	while (i[str] >= '0' && i[str] <= '9')
	{
		nb = nb * 10 + (i[str] - '0');
		i++;
	}
	res = (nb * sign) % 256;
	return (res);
}

int	ft_exit(t_minishell *shell, char **tab)
{
	int	exit_code;

	exit_code = 0;
	ft_dprintf(2, "exit\n");
	if (*tab)
	{
		if (!ft_numeric_argument_error(*tab))
		{
			ft_dprintf(STDERR_FILENO, "minishell: exit: %s: numeric argument"
				" required\n", *tab);
			shell->exit = 1;
			return (2);
		}
		if (1[tab])
			return (ft_dprintf(STDERR_FILENO, "minishell: exit: too many"
					" arguments\n"), 1);
		exit_code = ft_atoll(*tab);
	}
	else
		exit_code = shell->exit_status;
	shell->exit = 1;
	return (exit_code);
}
