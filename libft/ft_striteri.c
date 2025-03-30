/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 03:56:12 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/24 00:38:45 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// void	apply_test(unsigned int i, char *c)
// {
// 	*c = *c + i;
// }

// int	main(void)
// {
// 	char	str[] = "La chevalerie, c’est pas là où on range les chevaux ? ";

// 	ft_striteri(str, apply_test);
// 	printf("Résultat : %s\n", str);
// 	return (0);
// }
