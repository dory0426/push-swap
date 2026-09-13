/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:00:42 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/05 20:35:37 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos(t_stack *b, int target)
{
	int	pos;

	pos = 0;
	while (b)
	{
		if (b->index == target)
			return (pos);
		b = b->next;
		pos++;
	}
	return (-1);
}

static void	sort_pa(t_stack **a, t_stack **b, t_stats *sts)
{
	int	target;
	int	pos;
	int	size;

	size = ft_lstsize(*b);
	target = size - 1;
	while (*b)
	{
		pos = find_pos(*b, target);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b, sts);
		}
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rrb(b, sts);
		}
		pa(a, b, sts);
		target--;
		size--;
	}
}

void	chunk_sort(t_stack **a, t_stack **b, t_stats *sts)
{
	int	chunk;
	int	end;
	int	size;

	chunk = 2 * ft_sqrt(ft_lstsize(*a));
	if (chunk < 1)
		chunk = 1;
	end = chunk;
	size = ft_lstsize(*a);
	while (*a)
	{
		if ((*a)->index < end)
		{
			pb(a, b, sts);
			if ((*b)->index < end - chunk / 2)
				rb(b, sts);
		}
		else
			ra(a, sts);
		while (ft_lstsize(*b) >= end && end < size)
			end += chunk;
		if (end > size)
			end = size;
	}
	sort_pa(a, b, sts);
}
