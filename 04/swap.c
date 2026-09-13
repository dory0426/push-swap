/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:50:41 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/09 20:16:17 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*fst;
	t_stack	*sec;
	t_stack	*trd;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	fst = *stack;
	sec = fst->next;
	trd = sec->next;
	*stack = sec;
	sec->prev = NULL;
	sec->next = fst;
	fst->prev = sec;
	fst->next = trd;
	if (trd)
		trd->prev = fst;
}

void	sa(t_stack **a, t_stats *sts)
{
	swap(a);
	sts->sa++;
	sts->total++;
	ft_printf(1, "sa\n");
}

void	sb(t_stack **b, t_stats *sts)
{
	swap(b);
	sts->sb++;
	sts->total++;
	ft_printf(1, "sb\n");
}

void	ss(t_stack **a, t_stack **b, t_stats *sts)
{
	swap(a);
	swap(b);
	sts->ss++;
	sts->total++;
	ft_printf(1, "ss\n");
}
