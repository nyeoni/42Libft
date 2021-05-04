/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:22:20 by nkim              #+#    #+#             */
/*   Updated: 2021/05/04 16:07:20 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>

void    *memset(void *dest, int value, size_t len)
{
    size_t i;
    i = 0;

	while (i < len)
    {
        *((char *)dest+i) = value;
        i++;    
    }
    return dest;
}


int main(void)
{
    char arr[] = "abcdefgh";
    printf("%s\n", arr);

    memset(arr, 'c', 5 * sizeof(char));

    printf("%s\n", arr);
}