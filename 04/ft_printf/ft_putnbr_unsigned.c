/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 21:15:41 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/05 18:53:12 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n, int fd)
{
	int	count;

	count = 1;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10, fd);
	ft_putchar(n % 10 + '0', fd);
	return (count);
}
