/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:36:10 by lsellier          #+#    #+#             */
/*   Updated: 2025/03/30 20:26:36 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	ft_dputptr_hexa(unsigned long nb, int fd)
{
	int		i;

	i = 0;
	if (nb / 16)
		i += (ft_dputptr_hexa(nb / 16, fd));
	i += ft_dputchar(HEXA[nb % 16], fd);
	return (i);
}

int	ft_dputptr(void *ptr, int fd)
{
	int				count;
	unsigned long	nb;

	count = 0;
	if (!ptr)
		return (ft_dputstr("(nil)", fd));
	count += ft_dputstr("0x", fd);
	nb = (unsigned long)ptr;
	return (ft_dputptr_hexa(nb, fd) + count);
}
