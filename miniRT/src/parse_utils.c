/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:11:35 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 18:27:14 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

int	is_space(const char *str)
{
	if (*str == ' ' || *str == '\n' || *str == '\t' || \
		*str == '\f' || *str == '\r' || *str == '\v')
		return (1);
	return (0);
}

/**
 * strpbrk - Find the first occurrence of a set of characters
 * @cs: The string to be searched
 * @ct: The characters to search for
 */
static char	*ft_strpbrk(const char *cs, const char *ct)
{
	const char	*sc;

	sc = cs;
	while (*sc != '\0')
	{
		if (ft_strchr(ct, *sc))
			return ((char *)sc);
		++sc;
	}
	return (NULL);
}

/**
 * strsep - Split a string into tokens
 * @s: The string to be searched
 * @ct: The characters to search for
 * strsep() updates @s to point after the token, 
 * --> ready for the next call.
 */
char	*ft_strsep(char **s, const char *ct)
{
	char	*sbegin;
	char	*end;

	sbegin = *s;
	if (sbegin == NULL)
		return (NULL);
	end = ft_strpbrk(sbegin, ct);
	if (end)
		*end++ = '\0';
	*s = end;
	return (sbegin);
}

int	check_filename(const char *path)
{
	char	*idx;

	idx = ft_strrchr(path, '.');
	if (!idx)
		ft_error_msg("[filename].rt file does not exist.\n", 1);
	if (ft_strncmp(idx, ".rt", 4) != 0)
		ft_error_msg("[filename].rt file does not exist.\n", 1);
	return (0);
}
