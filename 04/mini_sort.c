/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:43:20 by yudakane          #+#    #+#             */
/*   Updated: 2026/08/09 20:34:56 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_3(t_stack **a, t_stats *sts)
{
	int	i0;
	int	i1;
	int	i2;

	i0 = (*a)->index;
	i1 = (*a)->next->index;
	i2 = (*a)->next->next->index;
	if (!(i0 > i1) && (i1 > i2) && !(i0 > i2))
	{
		sa(a, sts);
		ra(a, sts);
	}
	else if ((i0 > i1) && !(i1 > i2) && !(i0 > i2))
		sa(a, sts);
	else if (!(i0 > i1) && (i1 > i2) && (i0 > i2))
		rra(a, sts);
	else if ((i0 > i1) && !(i1 > i2) && (i0 > i2))
		ra(a, sts);
	else if ((i0 > i1) && (i1 > i2) && (i0 > i2))
	{
		sa(a, sts);
		rra(a, sts);
	}
}

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

void	mini_5(t_stack **a, t_stack **b, t_stats *sts)
{
	int	index;
	int	i;

	i = 0;
	while (i++ < 2)
	{
		index = find_min_index(*a);
		if (index <= ft_lstsize(*a) / 2)
		{
			while (index-- > 0)
				ra(a, sts);
		}
		else
		{
			index = ft_lstsize(*a) - index;
			while (index-- > 0)
				rra(a, sts);
		}
		pb(a, b, sts);
	}
	mini_3(a, sts);
	while (i-- > 0)
		pa(a, b, sts);
}
