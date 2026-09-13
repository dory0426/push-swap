/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:25:00 by myazawa           #+#    #+#             */
/*   Updated: 2026/07/27 21:37:11 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->prev = NULL;
	if (*lst == NULL)
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}
