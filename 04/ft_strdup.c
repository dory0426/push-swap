/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:44:53 by yudakane          #+#    #+#             */
/*   Updated: 2026/09/08 16:45:15 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		i;

	arr = (char *)malloc((sizeof (char)) * (ft_strlen(s) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		arr [i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
