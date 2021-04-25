/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:27:01 by treo              #+#    #+#             */
/*   Updated: 2021/04/25 19:21:28 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*head;

	if (!lst)
		return (NULL);
	tmp = lst;
	new = ft_lstnew(f(tmp->content));
	if (!new)
		return (NULL);
	head = new;
	lst = lst->next;
	while (lst)
	{
		tmp = lst;
		new->next = ft_lstnew(f(tmp->content));
		if (!(new->next))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
