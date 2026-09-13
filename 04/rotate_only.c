/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_only.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 13:13:27 by yudakane          #+#    #+#             */
/*   Updated: 2026/08/16 14:35:27 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_only(int i, t_stack **a, t_stats *sts)
{
	int	size;

	size = ft_lstsize(*a);
	if (i < size - i)
	{
		while (i--)
			ra(a, sts);
	}
	else
	{
		i = size - i;
		while (i--)
			rra(a, sts);
	}
}
