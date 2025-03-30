/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:28:53 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/23 04:55:53 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= 127)
// 	{
// 		if (ft_isalnum(i))
// 			printf("%d isalnum.\n", i);
// 		else
// 			printf("%d no isalnum.\n", i);
// 		i++;
// 	}
// 	return (0);
// }
