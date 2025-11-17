/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:51:56 by mmouis            #+#    #+#             */
/*   Updated: 2025/10/17 10:51:56 by mmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*p;
	unsigned char	f;
	char			*stck;

	if (s == NULL)
		return (NULL);
	p = (unsigned char *)s;
	f = (unsigned char)c;
	stck = NULL;
	if (f == '\0')
	{
		while (*p)
			p++;
		return ((char *)p);
	}
	while (*p)
	{
		if (*p == f)
		{
			stck = (char *)p;
		}
		p++;
	}
	return (stck);
}
