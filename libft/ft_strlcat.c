/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:03:20 by lsellier          #+#    #+#             */
/*   Updated: 2024/12/26 05:10:56 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	dest_len = 0;
	while (dest_len < size && dest[dest_len] != '\0')
		dest_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	i = dest_len;
	j = 0;
	while (src[j] != '\0' && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}

// #include <stdio.h>
// #include <string.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 	char	dest1[110] = "Ça prouve que j’ai "
// "de l’ubiquité ""… De l’humilité ? ";
// 	char	dest2[110] = "Ça prouve que j’ai "
// "de l’ubiquité ""… De l’humilité ? ";
// 	char	src[] = "C’est pas quand il y a des infiltrations ? ";
// 	size_t	size = 4;
// 	size_t	result1 = ft_strlcat(dest1, src, size);
// 	size_t	result2 = strlcat(dest2, src, size);

// 	printf("Résultat avec ft_strlcat : %s\n", dest1);
// 	printf("Résultat avec strlcat : %s\n", dest2);
// 	printf("Taille de la chaîne résultante avec ft_strlcat : %zu\n", result1);
// 	printf("Taille de la chaîne résultante avec strlcat : %zu\n", result2);
// 	if (strcmp(dest1, dest2) == 0 && result1 == result2)
// 		printf("Les résultats sont identiques.\n");
// 	else
// 		printf("Les résultats sont différents.\n");
// 	return (0);
// }
