/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 22:19:10 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/05 18:56:16 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr, int fd)
{
	int				count;
	unsigned long	p;

	if (!ptr)
		return (ft_putstr("(nil)", fd));
	p = (unsigned long)ptr;
	count = 0;
	count += ft_putstr("0x", fd);
	count += ft_putnbr_base(p, 16, fd);
	return (count);
}
