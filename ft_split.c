/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:28:59 by treo              #+#    #+#             */
/*   Updated: 2021/05/24 09:35:06 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char x, char charset)
{
	if (x == '\0')
		return (1);
	if (charset == x)
		return (1);
	return (0);
}

static int	get_ary_len(char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset)
			&& is_sep(str[i + 1], charset))
			count++;
		i++;
	}
	return (count);
}

static char	**malloc_error(char **s_ary)
{
	while (*s_ary)
		free(*(s_ary++));
	free(s_ary);
	return (NULL);
}

static char	**fill_ary(char *str, char **heap, char charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		j = i;
		if (is_sep(str[i], charset))
			j = ++i;
		else
		{
			while (!is_sep(str[j], charset))
				j++;
			heap[k] = (char *)malloc(sizeof(char) * (j - i + 1));
			if (!heap[k])
				return (malloc_error(heap));
			ft_strlcpy(heap[k], &str[i], j - i + 1);
			i = j;
			k++;
		}
	}
	heap[k] = 0;
	return (heap);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**res;

	len = get_ary_len((char *)s, c);
	res = ft_calloc(len + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	res = fill_ary((char *)s, res, c);
	return (res);
}
