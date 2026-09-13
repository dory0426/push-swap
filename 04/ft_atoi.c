/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:17:11 by myazawa           #+#    #+#             */
/*   Updated: 2026/09/09 14:19:58 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_blunk_and_sign(char *nptr, int *i)
{
	int	sign;

	sign = 1;
	while ((nptr[*i] >= '\t' && nptr[*i] <= '\r') || nptr[*i] == ' ')
		(*i)++;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			sign = -sign;
		(*i)++;
	}
	return (sign);
}

static void	atoi_error_for_int(uint64_t nb, int sign, int *err)
{
	if ((sign == 1 && nb > 2147483647) || (sign == -1 && nb > 2147483648))
		*err = 1;
}

static void	atoi_error_for_str(char *nptr, int index, int *err)
{
	if (!(nptr[index] >= '0' && nptr[index] <= '9'))
		*err = 1;
}

static void	atoi_error_end(char *nptr, int index, int *err)
{
	if (nptr[index] != '\0')
		*err = 1;
}

int	ft_atoi(char *nptr, int *err)
{
	int			i;
	int			sign;
	uint64_t	nb;

	i = 0;
	nb = 0;
	*err = 0;
	sign = check_blunk_and_sign(nptr, &i);
	atoi_error_for_str(nptr, i, err);
	while (!*err && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		atoi_error_for_int(nb, sign, err);
		i++;
	}
	if (!*err)
		atoi_error_end(nptr, i, err);
	if (*err)
		return (0);
	if (sign == -1)
		return ((int)(-(long long)nb));
	return ((int)nb);
}
