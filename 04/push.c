/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 21:42:24 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/09 20:16:40 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(dst, tmp);
}

void	pb(t_stack **a, t_stack **b, t_stats *sts)
{
	if (!*a || !a)
		return ;
	push(a, b);
	sts->pb++;
	sts->total++;
	ft_printf(1, "pb\n");
}

void	pa(t_stack **a, t_stack **b, t_stats *sts)
{
	if (!*b || !b)
		return ;
	push(b, a);
	sts->pa++;
	sts->total++;
	ft_printf(1, "pa\n");
}
