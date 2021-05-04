/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:10:01 by nkim              #+#    #+#             */
/*   Updated: 2021/05/04 23:09:01 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    size_t i;
    i = 0;

    while (i < n)
    {
        if (*((char *)src + i) != (char)c)
            *((char *)dst + i) = *((char *)src + i);
        else
            break;
        i++;
    } 
    return dst;
}

// int main(void)
// {
//     char arr[3] = "000";
//     char src[3] = "123";
//     ft_memccpy(arr, src, '2', 3 * sizeof(int));

//     for (int i = 0; i < 3; i++)
//     {
//         // printf("%c ", src[i]);
//         // printf("%c ", arr[i]);
//     }
//     printf("%d\n", sizeof(char *));
//     //qprintf("%p\n", arr);
// }