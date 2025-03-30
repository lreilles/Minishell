/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:58:46 by lsellier          #+#    #+#             */
/*   Updated: 2025/03/30 20:26:42 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dputstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_dputstr("(null)", fd));
	while (s[i])
		write(fd, &s[i++], 1);
	return (i);
}
