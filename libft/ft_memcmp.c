/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:43:06 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/23 08:08:41 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}

// int	main(void)
// {
// 	char	str1[] = "Je ne suis pas fou. Ma mère m’a fait passer des tests.";
// 	char	str2[] = "Je ne suis pas fou. ma mère m’a fait passer des tests.";
// 	char	str3[] = "Ie ne suis pas fou. Ma mère m’a fait passer des tests.";

// 	printf("%d\n", ft_memcmp(str1, str2, 50));
// 	printf("%d\n", ft_memcmp(str1, str3, 50));
// 	printf("%d\n", ft_memcmp(str3, str1, 50));
// 	return (0);
// }
