/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 20:33:45 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/05 18:57:42 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	execute(va_list *args, char c, int fd)
{
	int	count;

	count = 0;
	if (c == 'd')
		count += ft_putnbr(va_arg(*args, int), fd);
	if (c == 'c')
		count += ft_putchar(va_arg(*args, int), fd);
	if (c == 's')
		count += ft_putstr(va_arg(*args, char *), fd);
	if (c == 'p')
		count += ft_putpointer(va_arg(*args, void *), fd);
	if (c == 'i')
		count += ft_putnbr(va_arg(*args, int), fd);
	if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(*args, unsigned int), fd);
	if (c == 'x')
		count += ft_putnbr_base(va_arg(*args, unsigned int), 16, fd);
	if (c == 'X')
		count += ft_putnbr_base_upper(va_arg(*args, unsigned int), 16, fd);
	if (c == '%')
		count += ft_putchar('%', fd);
	return (count);
}

int	ft_printf(int fd, const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i + 1] && format[i] == '%')
		{
			count += execute(&args, format[i + 1], fd);
			i++;
		}
		else
			count += ft_putchar(format[i], fd);
		i++;
	}
	va_end(args);
	return (count);
}
