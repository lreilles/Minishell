/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:43:43 by lsellier          #+#    #+#             */
/*   Updated: 2024/11/15 02:31:47 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	int		sign;
	int		len;
	char	*str;

	len = len_nb(nb);
	str = malloc((len + 1) * sizeof(char));
	sign = 1;
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		sign *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[--len] = ((nb % 10) * sign) + '0';
		nb = nb / 10;
	}
	return (str);
}

// int	main(void)
// {
// 	printf("Test avec un nombre positif : %s\n", ft_itoa(12345));
// 	printf("Test avec un nombre négatif : %s\n", ft_itoa(-12345));
// 	printf("Test avec zéro : %s\n", ft_itoa(0));
// 	printf("Test avec INT_MIN : %s\n", ft_itoa(-2147483648));
// 	printf("Test avec INT_MAX : %s\n", ft_itoa(2147483647));
// 	return (0);
// }
