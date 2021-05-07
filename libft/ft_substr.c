/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:35:06 by nkim              #+#    #+#             */
/*   Updated: 2021/05/07 15:56:54 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_substr(char const *str, unsigned int start, size_t len)
{
    char *tmp;
    size_t i;
    
    if(!(tmp = malloc(len + 1)))
        return 0;
    i = 0;
    
    while (i < len)
    {
        tmp[i] = str[start + i];
        i++;
    }
    tmp[i] ='\0';
    return tmp;
}