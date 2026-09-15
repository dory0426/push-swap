/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_normalized.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 12:17:30 by yudakane          #+#    #+#             */
/*   Updated: 2026/09/15 14:05:15 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *argv, int c)
{
	int		cw;

	cw = 0;
	while (*argv)
	{
		while (*argv == c && *argv)
			argv++;
		cw++;
		while (*argv != c && *argv)
			argv++;
	}
	return (cw);
}

static int	split_by_space(char *str, char ***arr)
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
		(*arr)[count] = ft_substr(str, index, len);
		if (!(*arr)[count])
			return (-1);
		index += len;
		if (str[index] == ' ')
			index++;
		count++;
	}
	(*arr)[count] = NULL;
	return (0);
}

static void	*free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
	return (NULL);
}

char	**build_normalized(char *arg, int *real_argc)
{
	char	**arr;

	*real_argc = count_words(arg, ' ');
	arr = (char **)malloc(sizeof(char *) * (*real_argc + 1));
	if (!arr)
		return (NULL);
	if (split_by_space(arg, &arr))
		return (free_arr(arr));
	return (arr);
}
