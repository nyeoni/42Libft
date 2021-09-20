/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:43:00 by nkim              #+#    #+#             */
/*   Updated: 2021/06/23 00:11:15 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;

	if (lst)
	{
		if (!(res = (t_list *)malloc(sizeof(t_list))))
			return (0);
		res->content = (*f)(lst->content);
		tmp = res;
	}
	else
		return (0);
	while ((lst = lst->next))
	{
		if (!(tmp->next = (t_list *)malloc(sizeof(t_list))))
		{
			ft_lstclear(&res, del);
			return (0);
		}
		tmp = tmp->next;
		tmp->content = (*f)(lst->content);
	}
	tmp->next = NULL;
	return (res);
}
