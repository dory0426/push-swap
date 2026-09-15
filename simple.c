/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:04:33 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/09 19:36:39 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *stack)
{
	int	min;
	int	min_index;
	int	i;

	min = stack->index;
	min_index = 0;
	i = 0;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_index);
}

void	selection_sort(t_stack **a, t_stack **b, t_stats *sts)
{
	int	index;
	int	size;

	while (*a)
	{
		index = find_min_index(*a);
		size = ft_lstsize(*a);
		if (index <= size / 2)
		{
			while (index-- > 0)
				ra(a, sts);
		}
		else
		{
			index = size - index;
			while (index-- > 0)
				rra(a, sts);
		}
		pb(a, b, sts);
	}
	while (*b)
		pa(a, b, sts);
}
