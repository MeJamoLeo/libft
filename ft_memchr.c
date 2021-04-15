/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:39:11 by treo              #+#    #+#             */
/*   Updated: 2021/04/15 15:05:42 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr_s;
	unsigned char		uc;
	size_t				i;

	ptr_s = (const unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while(i < n)
	{
		if(*(ptr_s + i) == uc)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
