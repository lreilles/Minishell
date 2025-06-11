/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <ameduboi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:33:45 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/12 01:41:14 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		i++;
	return (write(1, s, i));
}

int	ft_putnnbr(int nbr)
{
	long	n;
	int		result;
	int		counter;

	result = 0;
	n = nbr;
	counter = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		counter = 1;
	}
	result = n % 10 + '0';
	n /= 10;
	if (n > 0)
		counter += ft_putnnbr(n);
	return (write(1, &result, 1) + counter);
}

int	ft_putunsignednnbr(unsigned int nbr)
{
	unsigned long	n;
	unsigned int	result;
	int				counter;

	counter = 0;
	n = nbr;
	result = n % 10 + '0';
	n /= 10;
	if (n > 0)
		counter += ft_putunsignednnbr(n);
	return (write(1, &result, 1) + counter);
}

int	ft_putnptr(uintptr_t ptr)
{
	int	nb;

	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	nb = ft_putnhex(ptr, 0);
	return (nb + 2);
}
