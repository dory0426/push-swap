/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:49:17 by myazawa           #+#    #+#             */
/*   Updated: 2026/09/13 18:35:33 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_push_swap(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	t_stats	sts;
	int		start_index;

	ft_memset(&sts, 0, sizeof(t_stats));
	start_index = 1;
	if (ft_strcmp(argv[1], "--bench") == 0)
		start_index++;
	if (argv[start_index] && (ft_strcmp(argv[start_index], "--simple") == 0
			|| ft_strcmp(argv[start_index], "--medium") == 0
			|| ft_strcmp(argv[start_index], "--complex") == 0
			|| ft_strcmp(argv[start_index], "--adaptive") == 0))
		start_index++;
	if (check_repeat(argv, argc - start_index, start_index))
		return (-1);
	a_stack = a(argv, start_index);
	b_stack = NULL;
	if (!a_stack || decide_index(a_stack))
		return (free_stack(&a_stack));
	if (flag_search(argv, &a_stack, &b_stack, &sts))
		return (free_stack(&a_stack));
	free_stack(&a_stack);
	free_stack(&b_stack);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**real_argv;
	int		real_argc;
	int		i;
	int		ret;

	if (argc < 2)
		return (0);
	real_argc = argc;
	real_argv = normalize_args(argc, argv, &real_argc);
	ret = run_push_swap(real_argc, real_argv);
	if (argc != real_argc)
	{
		i = 0;
		while (real_argv[i])
		{
			free(real_argv[i]);
			i++;
		}
		free(real_argv);
	}
	if (ret == -1)
		ft_printf(2, ERROR_MS);
	return (ret);
}
