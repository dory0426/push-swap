/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 20:30:51 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/05 18:52:28 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	change(int n, int type)
{
	char	base[17];
	char	base_upper[17];

	ft_strcpy(base, "0123456789abcdef");
	ft_strcpy(base_upper, "0123456789ABCDEF");
	if (type == -1)
		return (base[n]);
	if (type == 1)
		return (base_upper[n]);
	return ('\0');
}

int	ft_putnbr_base(unsigned long n, unsigned long base, int fd)
{
	unsigned long	i;
	int				count;

	if (base == 0)
		return (0);
	i = 1;
	count = 0;
	while (n / i >= base)
		i *= base;
	while (i > 0)
	{
		ft_putchar(change(n / i, -1), fd);
		count++;
		n %= i;
		i /= base;
	}
	return (count);
}

int	ft_putnbr_base_upper(unsigned int n, unsigned int base, int fd)
{
	unsigned int	i;
	int				count;

	if (base == 0)
		return (0);
	i = 1;
	count = 0;
	while (n / i >= base)
		i *= base;
	while (i > 0)
	{
		ft_putchar(change(n / i, 1), fd);
		count++;
		n %= i;
		i /= base;
	}
	return (count);
}

// int	main(void)
// {
// 	ft_putnbr_base(16, 16);
// 	ft_putnbr_base(10, 16);
// 	ft_putnbr_base(11, 16);
// 	ft_putnbr_base(12, 16);
// 	ft_putnbr_base(13, 16);
// 	ft_putnbr_base(14, 16);
// 	ft_putnbr_base(15, 16);
// 	ft_putnbr_base(24852, 16);
// 	ft_putnbr_base(21443647, 16);
// 	return (0);
// }
