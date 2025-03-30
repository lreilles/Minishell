/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 02:38:33 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/23 23:08:00 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// int	main(void)
// {
// 	const	char *str = "pas d'idée sorry";
// 	size_t	len;

// 	len = ft_strlen(str);
// 	printf("La longueur de la chaîne \"%s\" est : %zu\n", str, length);
// 	return (0);
// }
