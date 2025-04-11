/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:11:39 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/23 04:51:26 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// si faux return (0);
// sinon return (1);
// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= 127)
// 	{
// 		if (ft_isdigit(i))
// 			printf("%d isdigit.\n", i);
// 		else
// 			printf("%d no isdigit.\n", i);
// 		i++;
// 	}
// 	return (0);
// }
