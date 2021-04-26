/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 04:50:08 by treo              #+#    #+#             */
/*   Updated: 2021/04/25 22:47:48 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_l)
{
	t_list	*ptr;

	if (*lst)
	{
		ptr = ft_lstlast(*lst);
		ptr->next = new_l;
	}
	else
		*lst = new_l;
}
