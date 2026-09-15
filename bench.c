/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:18:39 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/09 20:46:39 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(t_stats *sts, double dis, const char *strategy)
{
	int	int_part;
	int	dec_part;

	if (!sts || !sts->bench_enabled)
		return ;
	int_part = (int)(dis * 100.0);
	dec_part = (int)((dis * 100.0 - int_part) * 100);
	if (dec_part < 0)
		dec_part = -dec_part;
	if (!strategy)
		strategy = "Adaptive";
	ft_printf(2, "[bench] disorder: %d.", int_part);
	if (dec_part < 10)
		ft_printf(2, "0");
	ft_printf(2, "%d%%\n", dec_part);
	ft_printf(2, "[bench] strategy: %s\n", strategy);
	ft_printf(2, "[bench] total_ops: %d\n", sts->total);
	ft_printf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n", sts->sa,
		sts->sb, sts->ss, sts->pa, sts->pb);
	ft_printf(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		sts->ra, sts->rb, sts->rr, sts->rra, sts->rrb, sts->rrr);
}
