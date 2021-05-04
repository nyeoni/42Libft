/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:22:20 by nkim              #+#    #+#             */
/*   Updated: 2021/05/04 15:18:50 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>

void    *memset(void *ptr, int value, size_t len)
{
    size_t i;
    i = 0;

	while (i < len)
    {
        *((char *)ptr+i) = value;
        i++;    
    }
    return ptr;
}


int main(void)
{
    char arr[] = "abcdefgh";
    printf("%s\n", arr);

    memset(arr, 'c', 5 * sizeof(char));

    printf("%s\n", arr);
}