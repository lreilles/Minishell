/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:02:47 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/27 05:48:46 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int debut, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (debut >= s_len)
		return (ft_strdup(""));
	if (len > s_len - debut)
		len = s_len - debut;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[debut + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// int	main(void)
// {
// 	char			*str = "Mais colonel à titre aromatique."
// 	" Je vous l'ai déjà dit, c'est pour le féliciter.";
// 	unsigned int	start = 5;
// 	size_t			len = 15;
// 	char			*result = ft_substr(str, start, len);

// 	if (result)
// 	{
// 		printf("Sous-chaîne extraite : '%s'\n", result);
// 		free(result);
// 	}
// 	else
// 		printf("Erreur lors de l'allocation de mémoire.\n");
// 	return (0);
// }
