/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 01:54:48 by treo              #+#    #+#             */
/*   Updated: 2021/04/20 06:57:07 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef HOGE_H
# define TEST_SUCCESS printf("Success\n")
# define TEST_FAILED printf("Failed\n")
# define TEST_KO printf("KO\n")
#endif
char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	unsigned int	len_tmp;
	char			*ptr;

	if (!(s1 && s2))
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);

	ptr = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	len_tmp = ft_strlcat(ptr, s1, len_s1 + 1);
	ft_strlcat(ptr, s2, len_tmp + len_s2 + 1);
	return (ptr);
}

int main()
{
	char *s1 = "where is my ";
	char *s2 = "malloc ???";
	char *s3 = "where is my malloc ???";

	char *res = ft_strjoin(s1, s2);
	if (!strcmp(res, s3))
		exit(TEST_SUCCESS);
	exit(TEST_FAILED);
}
