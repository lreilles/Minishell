/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 01:13:08 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/24 01:06:53 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}

// int	main(void)
// {
// 	int		*tableau;
// 	size_t	n = 5;
// 	size_t	i = 0;

// 	tableau = (int *)ft_calloc(n, sizeof(int));
// 	if (tableau == NULL)
// 	{
// 		printf("Échec de l'allocation mémoire\n");
// 		return (1);
// 	}
// 	while (i++ < n)
// 		printf("%d ", tableau[i]);
// 	printf("\n");
// 	free(tableau);
// 	return (0);
// }
