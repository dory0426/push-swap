/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_almost_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 14:35:53 by yudakane          #+#    #+#             */
/*   Updated: 2026/08/16 15:38:37 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_almost_sorted(t_stack *a)
{
	t_stack	*tmp;
	int		descents;
	int		needed;
	int		i;

	descents = 0;
	needed = 0;
	i = 0;
	tmp = a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
		{
			descents++;
			needed = i + 1;
		}
		tmp = tmp->next;
		i++;
	}
	if (tmp->value > a->value)
		descents++;
	if (!descents || descents == 1)
		return (needed);
	return (-1);
}
