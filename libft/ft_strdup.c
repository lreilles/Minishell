/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:53:02 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/24 04:01:41 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		len;

	len = ft_strlen(src) + 1;
	dst = malloc(sizeof(char) * len);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, len);
	return (dst);
}

// int	main(void)
// {
// 	const char	*str = "Du temps de Pendragon, on avait "
// 	"le sens du dramatique : le Lac, Stonehenge, Avalon…"
// 	" Maintenant, dès qu’ils croisent un dragon, ils font un meeting.";
// 	char		*str2 = ft_strdup(str);

// 	if (str2)
// 	{
// 		printf("%s\n", str2);
// 		free(str2);
// 	}
// 	else
// 		printf("Error d'allocation\n");
// 	return (0);
// }
