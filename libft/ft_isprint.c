/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:34:31 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/23 04:50:05 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= 127)
// 	{
// 		if (ft_isprint(i))
// 			printf("%d isprint.\n", i);
// 		else
// 			printf("%d no isprint.\n", i);
// 		i++;
// 	}
// 	return (0);
// }
