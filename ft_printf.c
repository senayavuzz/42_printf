/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syavuz <syavuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:37:37 by syavuz            #+#    #+#             */
/*   Updated: 2022/11/30 14:51:22 by syavuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char c, va_list list)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (c == 's')
		count += ft_str(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(list, int), 10, 0);
	else if (c == 'x')
		count += ft_putnbr(va_arg(list, unsigned int), 16, 0);
	else if (c == 'X')
		count += ft_putnbr(va_arg(list, unsigned int), 16, 1);
	else if (c == 'u')
		count += ft_putnbr(va_arg(list, unsigned int), 10, 0);
	else if (c == 'p')
		count += ft_pointer(va_arg(list, unsigned long), 16, 0);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		val;

	val = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			val += ft_control(*(str + 1), ap);
			str++;
		}
		else
			val += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (val);
}
