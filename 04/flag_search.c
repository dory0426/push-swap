/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:04:53 by myazawa           #+#    #+#             */
/*   Updated: 2026/09/09 15:18:49 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_bench(char *argv, t_stack **a, t_stack **b, t_stats *sts)
{
	int	needed;
	int	err;

	err = 0;
	needed = is_almost_sorted(*a);
	if (!needed)
		return (0);
	else if (needed > 0)
	{
		rotate_only(needed, a, sts);
		return (0);
	}
	if (ft_strcmp(argv, "--simple") == 0)
		selection_sort(a, b, sts);
	else if (ft_strcmp(argv, "--medium") == 0)
		chunk_sort(a, b, sts);
	else if (ft_strcmp(argv, "--complex") == 0)
		radix_sort(a, b, sts);
	else if (ft_lstsize(*a) == 3)
		mini_3(a, sts);
	else if (ft_lstsize(*a) == 5)
		mini_5(a, b, sts);
	else
		adaptive_sort(a, b, sts, &err);
	return (err);
}

static const char	*strategy_label(char *flag, double dis)
{
	if (ft_strcmp(flag, "--simple") == 0)
		return ("Simple / O(n^2)");
	if (ft_strcmp(flag, "--medium") == 0)
		return ("Medium / O(n √ n)");
	if (ft_strcmp(flag, "--complex") == 0)
		return ("Complex / O(n log n)");
	if (dis < 0.2)
		return ("Adaptive / O(n^2)");
	if (dis < 0.5)
		return ("Adaptive / O(n √ n)");
	return ("Adaptive / O(n log n)");
}

int	flag_search(char **argv, t_stack **a, t_stack **b, t_stats *sts)
{
	int			i;
	const char	*strategy_name;
	double		dis;
	int			err;

	i = 1;
	sts->bench_enabled = false;
	if (!argv || !argv[1])
		return (0);
	if (ft_strcmp(argv[1], "--bench") == 0)
	{
		sts->bench_enabled = true;
		i++;
	}
	if (!argv[i])
		return (0);
	err = 0;
	dis = disorder(*a, ft_lstsize(*a), &err);
	if (err)
		return (-1);
	strategy_name = strategy_label(argv[i], dis);
	if (do_bench(argv[i], a, b, sts))
		return (-1);
	print_bench(sts, dis, strategy_name);
	return (0);
}
