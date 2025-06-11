/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <ameduboi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:05:30 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/12 01:41:21 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char conversion, va_list args)
{
	int	counter;

	counter = 0;
	if (conversion == 'c')
		counter += ft_putnchar(va_arg(args, int));
	else if (conversion == 's')
		counter += ft_putnstr(va_arg(args, char *));
	else if (conversion == 'p')
		counter += ft_putnptr(va_arg(args, uintptr_t));
	else if (conversion == 'i' || conversion == 'd')
		counter += ft_putnnbr(va_arg(args, int));
	else if (conversion == 'u')
		counter += ft_putunsignednnbr(va_arg(args, unsigned int));
	else if (conversion == 'x')
		counter += ft_putnhex(va_arg(args, unsigned int), 0);
	else if (conversion == 'X')
		counter += ft_putnhex(va_arg(args, unsigned int), 1);
	else if (conversion == '%')
		counter = write(1, "%", 1);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		i;

	va_start(args, format);
	counter = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			counter += ft_format(format[++i], args);
		else
			counter += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (counter);
}
