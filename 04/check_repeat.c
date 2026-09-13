/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_repeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:39:55 by myazawa           #+#    #+#             */
/*   Updated: 2026/09/09 14:37:11 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*make_seq(char **argv, int argc, int start)
{
	int	*seq;
	int	i;
	int	err;

	i = start;
	seq = malloc(sizeof(int) * (size_t)argc);
	if (!seq)
		return (NULL);
	while (argv[i])
	{
		err = 0;
		seq[i - start] = ft_atoi(argv[i], &err);
		if (err)
		{
			free (seq);
			return (NULL);
		}
		i++;
	}
	return (seq);
}

int	check_repeat(char **argv, int size, int start)
{
	int	i;
	int	j;
	int	*seq;

	seq = make_seq(argv, size, start);
	if (!seq)
		return (-1);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (seq[i] == seq[j])
			{
				free(seq);
				return (-1);
			}
			j++;
		}
		i++;
	}
	free(seq);
	return (0);
}
