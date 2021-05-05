/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:56:37 by nkim              #+#    #+#             */
/*   Updated: 2021/05/04 23:07:09 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

void *ft_memmove(void *dst, void *src, size_t n)
{
    size_t i;
    i = 0;

    if (!dst && !src)
        return 0;

    if (dst <= src)
    {
        while (i < n)
        {
            *((char *)dst + i) = *((char *)src + i);
            i++;
        }
    }
    else
    {
        while (i < n)
        {
            *((char *)dst + (n - i - 1)) = *((char *)src + (n - i - 1));
            i++;
        }
    }
    return dst;
}

// int main(void)
// {
//     char dst[] = "aaaaaaaaaa";
//     char src[] = "bbbbbbbbbb";
    
//     memmove(dst, src, 5);
//     printf("dst : %s\n",dst);
// }