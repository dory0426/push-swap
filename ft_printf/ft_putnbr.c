/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:29:54 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/05 18:53:44 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int fd)
{
	long	nb;
	int		count;

	nb = n;
	count = 1;
	if (nb < 0)
	{
		count += ft_putchar('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10, fd);
	ft_putchar((nb % 10) + '0', fd);
	return (count);
}
