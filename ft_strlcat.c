/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:27:02 by treo              #+#    #+#             */
/*   Updated: 2021/04/22 22:55:02 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	i = 0;
	j = ft_strlen(dst);
	while (j + i < dstsize - 1)
	{
		*(dst + i + j) = *(src + i);
		i++;
	}
	*(dst + i + j) = '\0';
	return (ft_strlen(src) + j);
}
