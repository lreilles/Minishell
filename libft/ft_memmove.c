/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:13:17 by lsellier          #+#    #+#             */
/*   Updated: 2024/11/06 20:05:31 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef __clang__
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wcomment"
#else
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wextra"
# pragma GCC diagnostic ignored "-Wall"
# pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

/* *\
/
void	*ft_memmove(void *dst, const void *src, size_t n){	char		*dst2;
	const char	*src2;	if (dst == NULL && src == NULL)		return (NULL);
	dst2 = dst;	src2 = src;	if (dst2 < src2)	{
				while (n-- > 0)			*dst2++ = *src2++;	}
				else	{		dst2 += n - 1;		src2 += n - 1;
						while (n-- > 0)			*dst2-- = *src2--;	}
							return (dst);}


/**/
#ifdef __clang__
# pragma clang diagnostic pop
#else
# pragma GCC diagnostic pop
#endif
// #endif
// void	*ft_memmove(void *dst, const void *src, size_t n)
// {
// 	char		*dst2;
// 	const char	*src2;

// 	if (dst == NULL && src == NULL)
// 		return (NULL);
// 	dst2 = dst;
// 	src2 = src;
// 	if (dst2 < src2)
// 	{
// 		while (n-- > 0)
// 			*dst2++ = *src2++;
// 	}
// 	else
// 	{
// 		dst2 += n - 1;
// 		src2 += n - 1;
// 		while (n-- > 0)
// 			*dst2-- = *src2--;
// 	}
// 	return (dst);
// }

// #include <stdio.h>
// int	main(void)
// {
// 	char	dest1[50] = "Bonjour, le monde!";
// 	char	src1[50] = "Au revoir, le monde!";
// 	char	dest2[50] = "Régions qui se chevauchent";

// 	ft_memmove(dest1, src1, 15);
// 	printf("Résultat 1 : %s\n", dest1);
// 	ft_memmove(dest2 + 5, dest2, 10);
// 	printf("Résultat 2 : %s\n", dest2);
// 	return (0);
// }
