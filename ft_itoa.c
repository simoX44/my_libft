/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:43:08 by mmouis            #+#    #+#             */
/*   Updated: 2025/10/17 15:43:08 by mmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static	long	ft_if_nigativ(long n)
{
	long	nb;

	nb = n;
	if (n < 0)
		nb *= -1;
	return (nb);
}

static	int	ft_len_nb(long nb2, int n)
{
	size_t	len;

	len = 0;
	while (nb2)
	{
		len++;
		nb2 = nb2 / 10;
	}
	if (n < 0)
		len++;
	return (len);
}

static	char	*ft_is_zero(void)
{
	char	*zero;

	zero = malloc(sizeof(char) * 2);
	if (!zero)
		return (NULL);
	zero[0] = '0';
	zero[1] = '\0';
	return (zero);
}

char	*ft_itoa(int n)
{
	char	*str_nmb;
	long	nb;
	long	nb2;
	size_t	len;
	char	*num;

	num = "0123456789";
	if (n == 0)
		return (ft_is_zero());
	nb2 = ft_if_nigativ(n);
	len = ft_len_nb(nb2, n);
	str_nmb = malloc(sizeof(char) * (len + 1));
	if (!str_nmb)
		return (NULL);
	nb = ft_if_nigativ(n);
	str_nmb[len] = '\0';
	while (nb)
	{
		str_nmb[--len] = num[nb % 10];
		nb = nb / 10;
	}
	if (n < 0)
		str_nmb[0] = '-';
	return (str_nmb);
}
