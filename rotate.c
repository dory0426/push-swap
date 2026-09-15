/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:59:12 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/05 19:52:55 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*fst;
	t_stack	*lst;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	fst = *stack;
	lst = ft_lstlast(*stack);
	*stack = fst->next;
	(*stack)->prev = NULL;
	lst->next = fst;
	fst->prev = lst;
	fst->next = NULL;
}

void	ra(t_stack **a, t_stats *sts)
{
	rotate(a);
	sts->ra++;
	sts->total++;
	ft_printf(1, "ra\n");
}

void	rb(t_stack **b, t_stats *sts)
{
	rotate(b);
	sts->rb++;
	sts->total++;
	ft_printf(1, "rb\n");
}

void	rr(t_stack **a, t_stack **b, t_stats *sts)
{
	rotate(a);
	rotate(b);
	sts->rr++;
	sts->total++;
	ft_printf(1, "rr\n");
}
