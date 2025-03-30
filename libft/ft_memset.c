/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:37:58 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/21 02:55:08 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = s;
	while (n > 0)
	{
		*p++ = c;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	int	str1[10];
	int	str2[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		str1[i] = 128;
		str2[i] = 128;
		i++;
	}
	i = 0;
	printf("Avant ft_memset:\n");
	while (i < 10)
	{
		printf("str1[%d]: %d\n", i, str1[i]);
		i++;
	}
	i = 0;
	printf("Avant memset:\n");
	while (i < 10)
	{
		printf("str2[%d]: %d\n", i, str2[i]);
		i++;
	}
	ft_memset(str1, 128, sizeof(int) * 3);
	memset(str2, 128, sizeof(int) * 3);
	i = 0;
	printf("\nAprès ft_memset:\n");
	while (i < 10)
	{
		printf("str1[%d]: %d\n", i, str1[i]);
		i++;
	}
	i = 0;
	printf("\nAprès memset:\n");
	while (i < 10)
	{
		printf("str2[%d]: %d\n", i, str2[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	char str1[50] = "tiens voila un test";
	char str2[50] = "tiens voila un test";

	printf("Avant ft_memset:\n");
	printf("str1: %s\n", str1);
	printf("Avant memset:\n");
	printf("str2: %s\n", str2);
	ft_memset(str1, '*', 10);
	memset(str2, '*', 10);
	printf("\nAprès ft_memset:\n");
	printf("str1: %s\n", str1);
	printf("\nAprès memset:\n");
	printf("str2: %s\n", str2);
	return (0);
} */
