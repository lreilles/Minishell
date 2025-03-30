/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:54:33 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/23 23:32:36 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t len)
{
	size_t	len_to_find;
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (len > src_len)
		len = src_len;
	len_to_find = 0;
	while (to_find[len_to_find] != '\0')
		len_to_find++;
	if (len_to_find == 0)
		return ((char *)src);
	if (len == 0 || len < len_to_find)
		return (NULL);
	i = 0;
	if (len < len_to_find)
		return (NULL);
	while (i <= len - len_to_find)
	{
		if (ft_strncmp(src + i, to_find, len_to_find) == 0)
			return ((char *)(src + i));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*src = "Après-demain, à partir d'aujourd'hui ?";
// 	const char 	*to_find = "d'aujourd'hui";
// 	size_t	len = 50;
// 	char	*result = ft_strnstr(src, to_find, len);

// 	if (result != NULL)
// 		printf("La sous-chaîne '%s' a été trouvée : %s\n", to_find, result);
// 	else
// 		printf("La sous-chaîne '%s' n'a pas été trouvée.\n", to_find);
// 	return (0);
// }
