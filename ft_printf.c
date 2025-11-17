/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouis <mmouis@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:08:59 by mmouis            #+#    #+#             */
/*   Updated: 2025/10/24 12:08:59 by mmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int	ft_disim_string(char format, va_list arg)
{
	int	count;

	count = 0;
	if (format == 'd')
		count += ft_putnbr(va_arg(arg, int));
	else if (format == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (format == 'c')
		count += ft_print_char(va_arg(arg, int));
	else if (format == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (format == '%')
		count += write(1, "%%", 1);
	return (count);
}

int	ft_hex_ptr_unsig(char format, va_list arg)
{
	int	count;

	count = 0;
	if (format == 'x')
		count += ft_print_hex(va_arg(arg, unsigned int), format);
	else if (format == 'X')
		count += ft_print_hex(va_arg(arg, unsigned int), format);
	if (format == 'p')
		count += ft_print_pointer(va_arg(arg, void *));
	else if (format == 'u')
		count += ft_print_unsig(va_arg(arg, unsigned int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i' || *format == 'c'
				|| *format == 's' || *format == '%')
				count += ft_disim_string(*format, arg);
			else if (*format == 'p' || *format == 'u'
				|| *format == 'x' || *format == 'X')
				count += ft_hex_ptr_unsig(*format, arg);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(arg);
	return (count);
}
