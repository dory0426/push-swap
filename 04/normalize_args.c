/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:53:51 by yudakane          #+#    #+#             */
/*   Updated: 2026/09/08 18:27:46 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strchr(const char *s, int c)
{
	while ((unsigned char)*s != (unsigned char)c && *s)
		s++;
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	**normalize_args(int argc, char **argv, int *real_argc)
{
	int	last;

	last = argc - 1;
	if (ft_strchr(argv[last], ' '))
		return (build_normalized(argv, last, real_argc));
	return (argv);
}
