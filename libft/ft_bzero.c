/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:53:35 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/23 05:45:56 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *) s;
	while (n > 0)
	{
		*p++ = 0;
		n--;
	}
}

// int	main(void)
// {
// 	int		i;
// 	int		tab_int[20] = {1, 2, 3, 4, 5};
// 	int		tab_int2[20] = {1, 2, 3, 4, 5};
// 	char	str[] = "test de merde :)";
// 	char	str2[] = "test de merde :)";

// 	printf("Avant ft_bzero et bzero:\n%s\n", str);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d ", tab_int[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	ft_bzero(str, 5);
// 	ft_bzero(tab_int, sizeof(int) * 3);
// 	printf("Après ft_bzero:\n'%s'\n", str);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d ", tab_int[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	bzero(str2, 5);
// 	bzero(tab_int2, sizeof(int) * 3);
// 	printf("Après bzero:\n'%s'\n", str2);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d ", tab_int2[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }
