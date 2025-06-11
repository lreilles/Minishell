/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <ameduboi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:49:23 by ameduboi          #+#    #+#             */
/*   Updated: 2025/06/12 01:41:23 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_putnhex(unsigned long nbr, int m);
int	ft_putnptr(uintptr_t ptr);
int	ft_putnchar(char c);
int	ft_putnstr(char *s);
int	ft_putnnbr(int nbr);
int	ft_putunsignednnbr(unsigned int nbr);

#endif
