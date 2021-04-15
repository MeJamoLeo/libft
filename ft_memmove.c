/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:45:05 by treo              #+#    #+#             */
/*   Updated: 2021/04/15 14:34:39 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*rev_memcpy(void *dst, const void *src, size_t n)
{
	char		*ptr_d;
	const char	*ptr_s;

	ptr_d = dst + n - 1;
	ptr_s = src + n - 1;
	if (dst == NULL && src == NULL)
		return (0);
	while (n--)
		*ptr_d-- = *ptr_s--;
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
		rev_memcpy(dst, src, len);
	return (dst);
}
