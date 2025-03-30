/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 02:54:10 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/18 02:58:14 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int	sign;

	sign = 1;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		sign *= -1;
	}
	if (nb / 10)
	{
		ft_putnbr_fd((nb / 10 * sign), fd);
	}
	ft_putchar_fd((nb % 10) * sign + '0', fd);
}
