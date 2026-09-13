/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 12:52:54 by yudakane          #+#    #+#             */
/*   Updated: 2026/09/09 15:15:45 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return (-1);
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	return (-1);
}
