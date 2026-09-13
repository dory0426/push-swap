/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:46:29 by myazawa           #+#    #+#             */
/*   Updated: 2026/09/09 14:36:41 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*a(char **argv, int start)
{
	int		i;
	int		value;
	int		err;
	t_stack	*stack;
	t_stack	*new;

	stack = NULL;
	i = start;
	err = 0;
	while (argv[i])
	{
		value = ft_atoi(argv[i], &err);
		new = ft_lstnew(value, i - start);
		if (err || !new)
		{
			free_stack(&stack);
			return (NULL);
		}
		ft_lstadd_back(&stack, new);
		i++;
	}
	return (stack);
}

static int	*stack_to_ary(t_stack *a)
{
	int	*ary;
	int	i;

	i = 0;
	ary = malloc(sizeof(int) * ft_lstsize(a));
	if (!ary)
		return (NULL);
	while (a)
	{
		ary[i] = a->value;
		a = a->next;
		i++;
	}
	return (ary);
}

static int	*sort_ary(t_stack *a)
{
	int	*ary;
	int	size;
	int	tmp;
	int	i;
	int	j;

	ary = stack_to_ary(a);
	size = ft_lstsize(a);
	i = 0;
	while (ary && i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (ary[j] > ary[j + 1])
			{
				tmp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (ary);
}

int	decide_index(t_stack *a)
{
	int	*ary;
	int	size;
	int	i;

	ary = sort_ary(a);
	if (!ary)
		return (-1);
	size = ft_lstsize(a);
	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->value == ary[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
	free(ary);
	return (0);
}
