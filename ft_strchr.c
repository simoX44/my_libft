/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:51:56 by mmouis            #+#    #+#             */
/*   Updated: 2025/10/17 10:51:56 by mmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*p;
	unsigned char	f;

	p = (unsigned char *)s;
	f = (unsigned char)c;
	if (f == '\0')
	{
		while (*p)
			p++;
		return ((char *)p);
	}
	while (*p)
	{
		if (*p == f)
			return ((char *)p);
		p++;
	}
	return (NULL);
}
