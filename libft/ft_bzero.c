/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:00:36 by nkim              #+#    #+#             */
/*   Updated: 2021/05/04 23:30:24 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

void ft_bzero(void *src, size_t n)
{
    int i;
    i = 0;
    while (i < n)
    {
        *((char *)src + i) = 0;
        i++;
    }
}

// int main(void)
// {
//     char arr[] = "abcdefgh";
//     printf("%s\n", arr);

//     bzero(arr, 5 * sizeof(char));

//     printf("%s\n", arr);
//     for (int i = 0; i <  8; i++)
//     {
//         printf("%c ", arr[i]);
//     }
// }