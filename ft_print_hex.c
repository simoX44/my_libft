/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouis <mmouis@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:08:59 by mmouis            #+#    #+#             */
/*   Updated: 2025/10/24 12:08:59 by mmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_print_hex(unsigned int nbr, char x)
{
	char	*hex;
	char	*uper_hex;
	int		count;

	hex = "0123456789abcdef";
	uper_hex = "0123456789ABCDEF";
	count = 0;
	if (x == 'x' && nbr >= 16)
	{
		count += ft_print_hex(nbr / 16, x);
		count += ft_print_hex(nbr % 16, x);
	}
	else if (x == 'x' && nbr < 16)
		count += ft_print_char(hex[nbr]);
	else if (x == 'X' && nbr >= 16)
	{
		count += ft_print_hex(nbr / 16, x);
		count += ft_print_hex(nbr % 16, x);
	}
	else if (x == 'X' && nbr < 16)
		count += ft_print_char(uper_hex[nbr]);
	return (count);
}
