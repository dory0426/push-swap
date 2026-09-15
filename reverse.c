/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:11:53 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/05 19:53:00 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*fst;
	t_stack	*lst;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	fst = *stack;
	lst = ft_lstlast(*stack);
	lst->prev->next = NULL;
	lst->prev = NULL;
	lst->next = fst;
	fst->prev = lst;
	*stack = lst;
}

void	rra(t_stack **a, t_stats *sts)
{
	reverse(a);
	sts->rra++;
	sts->total++;
	ft_printf(1, "rra\n");
}

void	rrb(t_stack **b, t_stats *sts)
{
	reverse(b);
	sts->rrb++;
	sts->total++;
	ft_printf(1, "rrb\n");
}

void	rrr(t_stack **a, t_stack **b, t_stats *sts)
{
	reverse(a);
	reverse(b);
	sts->rrr++;
	sts->total++;
	ft_printf(1, "rrr\n");
}
