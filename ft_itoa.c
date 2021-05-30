/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:47:22 by treo              #+#    #+#             */
/*   Updated: 2021/05/30 14:17:19 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_string(char *dst, int n, unsigned int s_len)
{
	if (n < 0)
	{
		n *= -1;
		*(dst) = '-';
	}
	while (n >= 10)
	{
		*(dst + (s_len--) - 1) = (char)((n % 10) + '0');
		n /= 10;
	}
	*(dst + s_len - 1) = n + '0';
	*(dst + ft_strlen(dst)) = '\0';
	return (dst);
}

static int	digit_count(unsigned int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		s_len;
	int		tmp;
	char	*ptr;

	s_len = 0;
	tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (tmp < 0)
	{
		tmp *= -1;
		s_len += 1;
	}
	s_len += digit_count(tmp);
	ptr = malloc(sizeof(char) * s_len + 1);
	if (!ptr)
		return (NULL);
	fill_string(ptr, n, s_len);
	return (ptr);
}
