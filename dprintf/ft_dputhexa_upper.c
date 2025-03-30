/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputhexa_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:59:12 by lsellier          #+#    #+#             */
/*   Updated: 2025/03/30 20:25:48 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

int	ft_dputhexa_upper(unsigned int nb, int fd)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count = (ft_dputhexa_upper(nb / 16, fd));
	count += ft_dputchar(ft_toupper(HEXA[nb % 16]), fd);
	return (count);
}
