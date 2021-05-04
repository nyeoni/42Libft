/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:22:20 by nkim              #+#    #+#             */
/*   Updated: 2021/05/04 23:08:20 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

void    *ft_memset(void *dst, int value, size_t n)
{
    size_t i;
    i = 0;

	while (i < n)
    {
        *((char *)dst+i) = value;
        i++;    
    }
    return dst;
}


// int main(void)
// {
//     char arr[] = "abcdefgh";
//     printf("%s\n", arr);

//     ft_memset(arr, 'c', 5 * sizeof(char));

//     printf("%s\n", arr);
// }