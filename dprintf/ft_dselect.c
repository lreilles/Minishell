/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dselect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:17:04 by lsellier          #+#    #+#             */
/*   Updated: 2025/03/30 20:27:14 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dselect(const char format, va_list args, int fd)
{
	int	results;

	results = 0;
	if (format == 'c')
		results += ft_dputchar(va_arg(args, int), fd);
	else if (format == 's')
		results += ft_dputstr(va_arg(args, char *), fd);
	else if (format == 'p')
		results += ft_dputptr(va_arg(args, void *), fd);
	else if (format == 'd' || format == 'i')
		results += ft_dputnbr(va_arg(args, int), fd);
	else if (format == 'u')
		results += ft_dputunbr(va_arg(args, unsigned), fd);
	else if (format == 'x')
		results += ft_dputnbr_hexa(va_arg(args, unsigned), fd);
	else if (format == 'X')
		results += ft_dputhexa_upper(va_arg(args, unsigned int), fd);
	else if (format == '%')
		results += ft_dputchar('%', fd);
	return (results);
}
