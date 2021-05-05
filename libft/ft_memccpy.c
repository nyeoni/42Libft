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
// #include <string.h>
#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    size_t i;
    i = 0;

    while (i < n)
    {
        if (*((unsigned char *)src + i) != (unsigned char)c)
            *((unsigned char *)dst + i) = *((unsigned char *)src + i);
        else
        {
            *((unsigned char *)dst + i) = *((unsigned char *)src + i);
            i++;
            break;
        }
        i++;
    } 

    if (i != n)
        return ((unsigned char *)dst + i);
    else
        return 0;
}

// int main(void)
// {
//     char	src[] = "test basic du memccpy !";
// 	char	buff1[22];

//     memset(buff1, 0, sizeof(buff1));
// 	char	*r1 = memccpy(buff1, src, 'm', 22);
//     char	*r2 = ft_memccpy(buff1, src, 'm', 22);

//     for (int i = 0; i < 3; i++)
//     {
//         printf("r1: %c ", r1[i]);
//     }

//     for (int i = 0; i < 3; i++)
//     {
//         printf("r2 : %c ", r2[i]);
//     }
    // printf("%d\n", sizeof(char *));
    // //qprintf("%p\n", arr);
// }