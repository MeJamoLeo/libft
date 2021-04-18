/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:40:09 by treo              #+#    #+#             */
/*   Updated: 2021/04/18 16:34:49 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n)
		&& (*(s1 + i) == *(s2 + i))
		&& (*(s1 + i) != '\0'))
		i++;
	if (i == n)
		return (0);
	return ((int)((unsigned char) *(s1 + i) - (unsigned char) *(s2 + i)));
}
