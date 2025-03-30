/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:32:30 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/23 04:52:34 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= 127)
// 	{
// 		if (ft_isascii(i))
// 			printf("%d isascii.\n", i);
// 		else
// 			printf("%d no isascii.\n", i);
// 		i++;
// 	}
// 	return (0);
// }
