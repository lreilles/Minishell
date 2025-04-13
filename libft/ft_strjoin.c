/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:22:22 by lsellier          #+#    #+#             */
/*   Updated: 2025/04/13 02:48:16 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s3;
	char	*s3;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s3 = len_s1 + ft_strlen(s2) + 1;
	s3 = malloc(len_s3);
	if (!s3)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (i < len_s3 - 1)
	{
		s3[i] = s2[i - len_s1];
		i++;
	}
	s3[len_s3 - 1] = '\0';
	return (s3);
}

// int	main(void)
// {
// 	char	*s1 = "C’est vrai que c’est curieux ";
// 	char	*s2 = "cette manie de pas vouloir torture; ça vient de quoi, ça ? ";
// 	char	*result = ft_strjoin(s1, s2);

// 	if (result)
// 	{
// 		printf("Résultat de la concaténation : %s\n", result);
// 		free(result);
// 	}
// 	else
// 		printf("Échec de l'allocation mémoire.\n");
// 	return (0);
// }
