/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:17:03 by yudakane          #+#    #+#             */
/*   Updated: 2026/09/08 16:44:33 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*arr;
	size_t	min;
	size_t	i;

	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	min = ft_strlen(s) - start;
	if (min > len)
		min = len;
	arr = (char *)malloc((sizeof (char)) * (min + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (s[start + i] && i < min)
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
