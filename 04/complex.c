/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:40:08 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/03 19:59:41 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b, t_stats *sts)
{
	int	size;
	int	bits;
	int	bit;
	int	i;

	size = ft_lstsize(*a);
	bits = max_bits(*a);
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->index >> bit) & 1)
				ra(a, sts);
			else
				pb(a, b, sts);
			i++;
		}
		while (*b)
			pa(a, b, sts);
		bit++;
	}
}
