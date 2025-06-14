/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:00:46 by lsellier          #+#    #+#             */
/*   Updated: 2025/06/14 01:43:57 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_char;
	const char	*src_char;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_char = dst;
	src_char = src;
	while (n > 0)
	{
		dst_char[n - 1] = src_char[n - 1];
		n--;
	}
	return (dst);
}

// int	main(void)
// {
// 	const char	*src = "On pleure parce qu’on est triste. Par exemple,"
// 	" je pleure parce que les autres sont stupides. Et cela me rend triste.";
// 	char		dst[256];

// 	ft_memcpy(dst, src, strlen(src) + 1);
// 	printf("Chaîne copiée : %s\n", dst);
// 	return (0);
// }
