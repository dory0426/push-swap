/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:53:51 by yudakane          #+#    #+#             */
/*   Updated: 2026/09/15 14:01:41 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	argv_len(int argc, char **argv)
{
	int	i;
	int	len;
	int	all_len;

	all_len = 0;
	i = 0;
	while (i < argc)
	{
		len = 0;
		while (argv[i][len])
		{
			all_len++;
			len++;
		}
		i++;
	}
	all_len += argc - 1;
	return (all_len);
}

static char	*make_new_arg(int argc, char **argv)
{
	int		i;
	int		j;
	int		len;
	int		index;
	char	*new_arg;

	len = argv_len(argc, argv);
	new_arg = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_arg)
		return (NULL);
	i = 0;
	index = 0;
	while (i < argc)
	{
		if (i)
			new_arg[index++] = ' ';
		j = -1;
		while (argv[i][++j])
			new_arg[index++] = argv[i][j];
		i++;
	}
	new_arg[index] = '\0';
	return (new_arg);
}

char	**normalize_args(int argc, char **argv, int *real_argc)
{
	char	*new_arg;
	char	**arr;

	new_arg = make_new_arg(argc, argv);
	if (!new_arg)
		return (NULL);
	arr = build_normalized(new_arg, real_argc);
	free (new_arg);
	return (arr);
}
