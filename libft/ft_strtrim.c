/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 05:16:34 by lsellier          #+#    #+#             */
/*   Updated: 2024/10/24 04:06:16 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static int	est_dans__charset(char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *charset)
{
	char		*trim;
	size_t		len;
	const char	*fin;

	while (*s1 && est_dans__charset(*s1, charset))
		s1++;
	fin = s1 + ft_strlen(s1);
	while (fin > s1 && est_dans__charset(*(fin - 1), charset))
		fin--;
	len = fin - s1;
	trim = (char *)malloc(len + 1);
	if (!trim)
		return (NULL);
	ft_strncpy(trim, s1, len);
	trim[len] = '\0';
	return (trim);
}

// int	main(void)
// {
// 	char	*str1 = "   Du passé faisons table en marbre.   ";
// 	char	*charset1 = " ";
// 	char	*result1 = ft_strtrim(str1, charset1);
// 	printf("Original: '%s'\n'%s'\n", str1, result1);
// 	free(result1);

// 	char *str2 = "***Du passé faisons table en marbre.***";
// 	char *charset2 = "*";
// 	char *result2 = ft_strtrim(str2, charset2);
// 	printf("Original: '%s'\n'%s'\n", str2, result2);
// 	free(result2);

// 	char *str3 = "   ***Du passé faisons table en marbre.***   ";
// 	char *charset3 = " *";
// 	char *result3 = ft_strtrim(str3, charset3);
// 	printf("Original: '%s'\n'%s'\n", str3, result3);
// 	free(result3);
// 	return (0);
// }
