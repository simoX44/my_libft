/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouis <mmouis@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:08:59 by mmouis            #+#    #+#             */
/*   Updated: 2025/10/24 12:08:59 by mmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			count += write(1, "-2147483648", 11);
			return (count);
		}
		count += write(1, "-", 1);
		n *= -1;
		count += ft_putnbr(n);
		return (count);
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_print_char((n % 10) + '0');
	return (count);
}
