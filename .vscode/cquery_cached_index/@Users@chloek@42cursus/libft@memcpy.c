/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:56:08 by nkim              #+#    #+#             */
/*   Updated: 2021/05/04 16:56:20 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// void *memcpy(void *dest, const void *src, size_t len)
// {
//     return NULL;
// }

int main(void)
{
    int arr[3];
    int src[3] = {1,2,3};
    memcpy(arr, src, 3 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", src[i]);
    }
    //qprintf("%p\n", arr);
}