/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 05:22:25 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/23 05:24:33 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	if (*str == '\0')
		return (0);
	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
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
