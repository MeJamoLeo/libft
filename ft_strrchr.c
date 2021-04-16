/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:55:35 by treo              #+#    #+#             */
/*   Updated: 2021/04/16 14:59:35 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (ft_strchr(s, c) == NULL)
		return (NULL);
	while (*(s + i))
		i++;
	while (*(s + i) != c)
		i--;
	return ((char *)(s + i));
}
