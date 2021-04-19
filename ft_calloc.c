/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 08:40:16 by treo              #+#    #+#             */
/*   Updated: 2021/04/19 14:51:05 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;
	ptr = malloc(count * sizeof(size));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * sizeof(size));
	return (ptr);
}
