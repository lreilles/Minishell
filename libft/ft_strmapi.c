/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:15:19 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/23 23:54:44 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;

	len = 0;
	while (s[len] != '\0')
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		result[len] = f(len, s[len]);
		len++;
	}
	result[len] = '\0';
	return (result);
}

// char	test(unsigned int i, char chartest)
// {
// 	return (chartest + i);
// }

/* int	main(void)
{
	char	*str = "bonjour le monde";
	char	*result;

	result = ft_strmapi(str, test);
	if (result)
	{
		printf("Chaîne d'origine: %s\n", str);
		printf("Chaîne transformée: %s\n", result);
		free(result);
	}
	else
		printf("Erreur d'allocation mémoire.\n");
	return (0);
} */
