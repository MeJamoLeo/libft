/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:36:26 by treo              #+#    #+#             */
/*   Updated: 2021/04/13 16:39:36 by treo             ###   ########.fr       */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		if (*(s + i) == (unsigned char)c)
			return (dst + i + 1);
		*(d + i) = *(s + i);
		i++;
	}
	return (NULL);
}
