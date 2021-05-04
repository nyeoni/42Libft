/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:56:08 by nkim              #+#    #+#             */
/*   Updated: 2021/05/04 23:08:33 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;
    i = 0;
    
    while (i < n)
    {
        *((char *)dst + i) = *((char *)src + i);
        i++;
    }
    return dst;
}

// int main(void)
// {
//     int arr[3];
//     int src[3] = {1,2,3};
//     ft_memcpy(arr, src, 3 * sizeof(int));

//     for (int i = 0; i < 3; i++)
//     {
//         printf("%d ", src[i]);
//     }
//     //qprintf("%p\n", arr);
// }