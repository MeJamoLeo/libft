/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:44:11 by treo              #+#    #+#             */
/*   Updated: 2021/04/21 13:55:57 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_contain(char c, char *set)
{
	int	i;

	i = 0;
	while (*(set + i) != '\0')
	{
		if (c == *(set + i))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*rtn;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (is_contain(*(s1 + start), (char *)set))
		start++;
	if (start == ft_strlen(s1))
	{
		rtn = ft_strdup("");
		if (rtn)
			return (rtn);
		return (NULL);
	}
	while (is_contain(*(s1 + end - 1), (char *)set))
		end--;
	rtn = ft_substr(s1, start, end - start);
	return (rtn);
}
