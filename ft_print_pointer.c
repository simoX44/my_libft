/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouis <mmouis@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:08:59 by mmouis            #+#    #+#             */
/*   Updated: 2025/10/24 12:08:59 by mmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_cope(int count, void *ptr, char *str)
{
	size_t			i;
	unsigned long	p;
	char			*hx;

	hx = "0123456789abcdef";
	i = count;
	str[i] = '\0';
	str[0] = '0';
	str[1] = 'x';
	p = (unsigned long)ptr;
	while (p)
	{
		str[--i] = hx[p % 16];
		p = p / 16;
	}
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	p;
	char			*str;
	int				count;

	count = 0;
	p = (unsigned long)ptr;
	if (p == 0)
		return (write(1, "(nil)", 5));
	while (p)
	{
		p = p / 16;
		count++;
	}
	str = malloc(sizeof(char) * (count + 3));
	if (!str)
	{
		write(1, "malloc failed!\n", 15);
		return (15);
	}
	count += 2;
	ft_cope(count, ptr, str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}
