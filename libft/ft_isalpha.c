/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 08:21:48 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/23 04:54:41 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int l)
{
	if (!(l >= 'a' && l <= 'z'))
	{
		if (!(l >= 'A' && l <= 'Z'))
			return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= 127)
// 	{
// 		if (ft_isalpha(i))
// 			printf("%d isalpha.\n", i);
// 		else
// 			printf("%d no isalpha.\n", i);
// 		i++;
// 	}
// 	return (0);
// }
