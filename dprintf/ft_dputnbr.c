/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 03:00:00 by lsellier          #+#    #+#             */
/*   Updated: 2025/03/30 20:26:14 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dputnbr(int nb, int fd)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (nb < 0)
	{
		i += ft_dputchar('-', fd);
		sign *= -1;
	}
	if (nb / 10)
		i += ft_dputnbr((nb / 10 * sign), fd);
	i += ft_dputchar((nb % 10) * sign + '0', fd);
	return (i);
}
