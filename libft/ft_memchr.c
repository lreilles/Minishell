/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:09:00 by lsellier          #+#    #+#             */
/*   Updated: 2024/11/01 20:09:00 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		if (*p == (char)c)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "";
// 	char	*result;

// 	result = ft_memchr(str, 'm', strlen(str));
// 		printf("%c\n", *result);
// 	else
// 		printf("Caractère non trouvé.\n");
// 	return (0);
// }
