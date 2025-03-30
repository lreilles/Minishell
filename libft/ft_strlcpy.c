/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:50:37 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/24 00:00:09 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	if (size > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[src_len] != '\0')
		src_len++;
	return (src_len);
}

// int	main(void)
// {
// 	char	src[] = "Bonjour, monde !";
// 	char	dest1[20];
// 	char	dest2[20];

// 	size_t	len1 = ft_strlcpy(dest1, src, 10);
// 	printf("ft_strlcpy : %s (len = %zu)\n", dest1, len1);

// 	size_t	len2 = strlcpy(dest2, src, 10);
// 	printf("strlcpy : %s (len = %zu)\n", dest2, len2);

// 	if (strcmp(dest1, dest2) == 0 && len1 == len2)
// 		printf("Les résultats sont identiques.\n");
// 	else
// 		printf("Les résultats sont différents.\n");
// 	return (0);
// }
