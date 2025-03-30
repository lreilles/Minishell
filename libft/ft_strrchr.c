/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:49:34 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/24 01:23:22 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*derniere_occurence;

	derniere_occurence = (NULL);
	while (*s != '\0')
	{
		if (*s == (char) c)
			derniere_occurence = (char *) s;
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (derniere_occurence);
}

// int	main(void)
// {
// 	const char	*str = "La patience est un plat qui se mange sans sauce.";
// 	char		c = 'a';
// 	char		*result;

// 	result = ft_strrchr(str, c);
// 	if (result)
// 	{
// 		printf("La dernière occurrence de '%c' se"
// 			" trouve à l'adresse : %p\n", c, result);
// 		printf("Sous-chaîne à partir de la dernière occurrence : %s\n", result);
// 	}
// 	else
// 		printf("Le caractère '%c' n'a pas été trouvé dans la chaîne.\n", c);
// 	return (0);
// }

// int	main(void)
// {
// 	const char	*str = "la géologie, c’est une Kardashian de la science.";
// 	char		ch = 'l';
// 	char		*result;

// 	result = ft_strrchr(str, ch);
// 	if (result)
// 		printf("La première occurrence de '%c' "
// 		"est trouvée à : %s\n", ch, result);
// 	else
// 		printf("Le caractère '%c' n'a pas été trouvé.\n", ch);
// 	return (0);
// }
