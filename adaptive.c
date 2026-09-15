/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 20:23:46 by myazawa           #+#    #+#             */
/*   Updated: 2026/09/09 15:14:09 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	misorder(int *ary, int size)
{
	double	mistakes;
	double	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1.0;
			if (ary[i] > ary[j])
				mistakes += 1.0;
			j++;
		}
		i++;
	}
	free(ary);
	return (mistakes / total_pairs);
}

double	disorder(t_stack *a, int size, int *err)
{
	int	*ary;
	int	i;

	*err = 0;
	if (size <= 1)
		return (0.0);
	ary = malloc(sizeof(int) * size);
	if (!ary)
	{
		*err = 1;
		return (0.0);
	}
	i = 0;
	while (a)
	{
		ary[i++] = a->value;
		a = a->next;
	}
	return (misorder(ary, size));
}

void	adaptive_sort(t_stack **a, t_stack **b, t_stats *sts, int *err)
{
	double	dis;

	dis = disorder(*a, ft_lstsize(*a), err);
	if (*err)
		return ;
	if (dis < 0.2)
		selection_sort(a, b, sts);
	if (dis >= 0.2 && dis < 0.5)
		chunk_sort(a, b, sts);
	if (dis >= 0.5)
		radix_sort(a, b, sts);
}
