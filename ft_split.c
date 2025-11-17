/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:51:56 by mmouis            #+#    #+#             */
/*   Updated: 2025/10/17 10:51:56 by mmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h" 

static	void	ft_free(char **st, size_t n)
{
	while (n > 0)
		free(st[--n]);
	free(st);
}

static	size_t	ft_word_count(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		if (str[i] == c)
			i++;
	}
	return (count);
}

static	char	*ft_aloc(const char *str, char c)
{
	size_t	i;
	char	*dub;
	size_t	len_word;

	i = 0;
	len_word = 0;
	while (str[len_word] && str[len_word] != c)
		len_word++;
	dub = malloc(sizeof(char) * (len_word + 1));
	if (!dub)
		return (NULL);
	while (*str && *str != c)
	{
		dub[i] = *str;
		str++;
		i++;
	}
	dub[i] = '\0';
	return (dub);
}

static	char	**ft_make(char **ary, const char *s, char c)
{
	size_t	i;
	size_t	x;

	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			ary[x++] = ft_aloc(&s[i], c);
			if (!ary[x - 1])
			{
				ft_free(ary, x);
				return (NULL);
			}
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	ary[x] = NULL;
	return (ary);
}

char	**ft_split(char const *s, char c)
{
	char	**ary;
	size_t	ar_len;

	if (s == NULL)
		return (NULL);
	ar_len = ft_word_count(s, c);
	ary = malloc(sizeof(char *) * (ar_len + 1));
	if (!ary)
		return (NULL);
	ary = ft_make(ary, s, c);
	return (ary);
}
