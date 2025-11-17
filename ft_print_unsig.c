/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouis <mmouis@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:08:59 by mmouis            #+#    #+#             */
/*   Updated: 2025/10/24 12:08:59 by mmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdlib.h> */
#include <unistd.h>
#include "libft.h"

int	ft_print_unsig(unsigned int u)
{
	int		count;
	char	*dism;

	count = 0;
	dism = "0123456789";
	if (u >= 10)
	{
		count += ft_print_unsig(u / 10);
	}
	count += ft_print_char(dism[u % 10]);
	return (count);
}
