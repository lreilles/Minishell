/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 03:51:47 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/23 23:17:28 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *s1 && *s2)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
		i++;
	}
	if (i < n)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}

// int	main(void)
// {
// 	const char	*str1 = "Faut pas respirer la compote, ça fait tousser.";
// 	const char	*str2 = "Faut pas respirer la compote, ça fait tousser.";
// 	const char	*str3 = "Faut pas respirer la compote, ça fait tousser!";
// 	int	result1 = ft_strncmp(str1, str2, strlen(str1));
// 	int	result2 = ft_strncmp(str1, str3, strlen(str1));

// 	printf("résultat: %d\n", result1);
// 	printf("résultat: %d\n", result2);
// 	return (0);
// }
