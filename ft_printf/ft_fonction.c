/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:15:34 by ameduboi          #+#    #+#             */
/*   Updated: 2024/11/07 22:48:01 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnhex(unsigned long nbr, int m)
{
	unsigned long	n;
	unsigned long	result;
	char			*base;
	int				counter;

	n = nbr;
	base = 0;
	counter = 0;
	if (m == 0)
		base = "0123456789abcdef";
	else if (m == 1)
		base = "0123456789ABCDEF";
	result = base[n % 16];
	n /= 16;
	if (n > 0)
		counter += ft_putnhex(n, m);
	return (write(1, &result, 1) + counter);
}
