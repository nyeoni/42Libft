/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:17:03 by nkim              #+#    #+#             */
/*   Updated: 2021/05/05 21:30:13 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s1)
{
    int size;
    char *res;
    size = ft_strlen(s1);
    
    if (!(res = malloc(size + 1)))
        return 0;
    
    size = 0;
    while (s1[size])
    {
        res[size] = s1[size];
        size++;
    }
    res[size] = '\0';
    return res;
}