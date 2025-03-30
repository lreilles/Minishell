/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 00:55:53 by lsellier          #+#    #+#             */
/*   Updated: 2025/03/30 20:26:55 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dputunbr(int n, int fd)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = (unsigned int)n;
	if (nb > 9)
		i += ft_dputnbr(nb / 10, fd);
	i += ft_dputchar((nb % 10) + '0', fd);
	return (i);
}
