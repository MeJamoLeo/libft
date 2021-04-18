/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:01:37 by treo              #+#    #+#             */
/*   Updated: 2021/04/19 06:30:45 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isover(long long res, long long next_num)
{
	long long	ov_div;
	long long	ov_mod;

	ov_div = LONG_LONG_MAX / 10;
	ov_mod = LONG_LONG_MAX % 10;
	if (res > ov_div)
		return (1);
	if ((res == ov_div) && (next_num > ov_mod))
		return (1);
	return (0);
}

static char	*ft_trimbrank(const char *str)
{
	while ((*str != '\0')
		&& (*str == ' ' || *str == '\f' || *str == '\n'
			|| *str == '\r' || *str == '\t' || *str == '\v'))
		str++;
	return ((char *)str);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	str = ft_trimbrank(str);
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && ('0' <= *str && *str <= '9'))
	{
		if (ft_isover(res, *(str + 1) - '0'))
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
		res *= 10;
		res += *(str++) - '0';
	}
	return (res * sign);
}
