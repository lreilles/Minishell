/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameduboi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:05:47 by ameduboi          #+#    #+#             */
/*   Updated: 2024/10/25 02:49:08 by ameduboi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
		result = result * 10 + nptr[i++] - 48;
	result *= sign;
	return (result);
}

// int main()
// {
// 	printf("Test 1 : ft_atoi(\"123\") = %d\n", ft_atoi("123"));
// 	printf("Test 2 : ft_atoi(\"-456\") = %d\n", ft_atoi("-456"));
// 	printf("Test 3 : ft_atoi(\"+789\") = %d\n", ft_atoi("+789"));
// 	printf("Test 4 : ft_atoi(\"   012\") = %d\n", ft_atoi("   012"));
// 	printf("Test 5 : ft_atoi(\"-  345\") = %d\n", ft_atoi("-  345"));
// 	printf("Test 6 : ft_atoi(\"abc\") = %d\n", ft_atoi("abc"));
// 	printf("Test 7 : ft_atoi(\"123abc\") = %d\n", ft_atoi("123abc"));
// 	printf("Test 8 : ft_atoi(\"\") = %d\n", ft_atoi(""));
// 	printf("Test 9 : ft_atoi(\" \") = %d\n", ft_atoi(" "));
// 	printf("Test 10 : ft_atoi(\"   \") = %d\n", ft_atoi("   "));
// 	return (0);
// }
