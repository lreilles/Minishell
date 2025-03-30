/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:10:27 by lsellier          #+#    #+#             */
/*   Updated: 2025/03/30 20:26:01 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dputnbr_hexa(unsigned int nb, int fd)
{
	int	base_len;
	int	i;

	base_len = 16;
	i = 0;
	if (nb / base_len)
		i += ft_dputnbr_hexa((nb / base_len), fd);
	i += ft_dputchar(HEXA[(nb % base_len)], fd);
	return (i);
}
