/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:33:52 by jbergos           #+#    #+#             */
/*   Updated: 2025/03/30 20:24:55 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H
# define HEXA "0123456789abcdef"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_dprintf(int fd, const char *format, ...);
int	ft_dputchar(int c, int fd);
int	ft_dputstr(char *s, int fd);
int	ft_dputptr(void *ptr, int fd);
int	ft_dputnbr(int nb, int fd);
int	ft_dputunbr(int n, int fd);
int	ft_dputnbr_hexa(unsigned int n, int fd);
int	ft_dputhexa_upper(unsigned int n, int fd);
int	ft_dselect(const char format, va_list args, int fd);
#endif
