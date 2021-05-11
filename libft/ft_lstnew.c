/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 02:49:19 by nkim              #+#    #+#             */
/*   Updated: 2021/05/11 02:53:32 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *res;
    if (!(res = (t_list *)malloc(sizeof(t_list))))
        return 0;
    res->content = content;
    res->next = NULL;

    return res;
}