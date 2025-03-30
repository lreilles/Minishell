/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 04:27:41 by lsellier          #+#    #+#             */
/*   Updated: 2025/03/30 20:27:25 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

/**
 * @brief Imprime des données formatées dans un fichier donné.
 *
 * Cette fonction prend en paramètre un descripteur de fichier, une chaîne de
 * format et une liste d'arguments variables. Elle parcourt la chaîne de format
 * caractère par caractère et effectue les actions correspondantes.
 * Si un caractère '%' est rencontré,
	la fonction appelle ft_fselect pour traiter
 * le caractère suivant et ajoute le résultat à la variable results. Sinon,
 * la fonction appelle ft_fputchar pour écrire le caractère dans le fichier et
 * ajoute 1 à la variable results. La fonction retourne le nombre total de
 * caractères écrits dans le fichier.
 *
 * @param fd Le descripteur de fichier dans lequel écrire les données formatées.
 * @param format La chaîne de format spécifiant comment les données doivent
 * être formatées.
 * @param ... La liste d'arguments variables à formater et à écrire
 * dans le fichier.
 * @return Le nombre total de caractères écrits dans le fichier.
 */
int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		results;
	int		i;

	i = 0;
	results = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			results += ft_dselect(*(format + i + 1), args, fd);
			++i;
		}
		else
			results += ft_dputchar(format[i], fd);
		++i;
	}
	va_end(args);
	return (results);
}
