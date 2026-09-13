/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_normalized.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 12:17:30 by yudakane          #+#    #+#             */
/*   Updated: 2026/09/13 15:53:52 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char **argv, int last, int c)
{
	int		cw;
	char	*s;

	s = argv[last];
	cw = last;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		cw++;
		while (*s != c && *s)
			s++;
	}
	return (cw);
}

static int	split_by_space(char *str, char ***arr, int i)
{
	int	index;
	int	len;
	int	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		while (str[index] == ' ')
			index++;
		if (!str[index])
			break ;
		len = 0;
		while (str[index + len] && str[index + len] != ' ')
			len++;
		(*arr)[i + count] = ft_substr(str, index, len);
		if (!(*arr)[i + count])
			return (-1);
		index += len;
		if (str[index] == ' ')
			index++;
		count++;
	}
	(*arr)[i + count] = NULL;
	return (0);
}

static int	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
	ft_printf(2, ERROR_MS);
	return (1);
}

char	**build_normalized(char **argv, int last, int *real_argc)
{
	char	**arr;
	int		i;

	*real_argc = count_words(argv, last, ' ');
	arr = (char **)malloc(sizeof(char *) * (*real_argc + 1));
	if (!arr)
	{
		ft_printf(2, ERROR_MS);
		exit (-1);
	}
	i = 0;
	while (i < last)
	{
		arr[i] = ft_strdup(argv[i]);
		if (!arr[i])
			exit (free_arr(arr));
		i++;
	}
	if (split_by_space(argv[last], &arr, i))
		exit (free_arr(arr));
	return (arr);
}
