/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:35:16 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/24 00:46:47 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*rs;
	unsigned char	uc;

	rs = (char *) s;
	uc = (unsigned char)c;
	while (*rs != '\0')
	{
		if ((unsigned char)*rs == uc)
			return (rs);
		rs++;
	}
	if (uc == '\0')
		return (rs);
	return (NULL);
}

// int	main(void)
// {
// 	const char	*str = "la géologie, c’est une Kardashian de la science.";
// 	char		ch = 'l';
// 	char		*result;

// 	result = ft_strchr(str, ch);
// 	if (result)
// 		printf("La première occurrence de '%c'"
// 		" est trouvée à : %s\n", ch, result);
// 	else
// 		printf("Le caractère '%c' n'a pas été trouvé.\n", ch);
// 	return (0);
// }
