/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:31:47 by treo              #+#    #+#             */
/*   Updated: 2021/04/18 03:11:57 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*(needle) == '\0')
		return ((char *)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	i = 0;
	while (*(haystack + i) != '\0' && i < len)
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j) && i + j < len)
		{
			j++;
			if (*(needle + j) == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
