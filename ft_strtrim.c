/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:51:56 by mmouis            #+#    #+#             */
/*   Updated: 2025/10/17 10:51:56 by mmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static	char	*ft_alooci(size_t start, size_t end, const char *s1)
{
	size_t	len_s;
	char	*trim;
	size_t	len_trim;

	len_s = ft_strlen(s1);
	if (start >= len_s)
		return (ft_strdup(""));
	len_trim = end - start + 1;
	trim = malloc(sizeof(char) * (len_trim + 1));
	if (!trim)
		return (NULL);
	ft_memcpy(trim, s1 + start, len_trim);
	trim[len_trim] = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	len_s;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	len_s = ft_strlen(s1);
	end = len_s - 1;
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[end]))
		end--;
	trim = ft_alooci(start, end, s1);
	return (trim);
}
