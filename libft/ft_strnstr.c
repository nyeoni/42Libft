/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:36:25 by nkim              #+#    #+#             */
/*   Updated: 2021/05/05 20:43:13 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;
    char *res;
    i = 0;

    if (needle[0] == '\0')
        return (char *)haystack;
    
    while (i < len && haystack[i])
    {
        if (haystack[i] == needle[0])
        {
            res = (char *) &haystack[i];
            j = 1;
            while ((haystack[i] == needle[j]) && needle[j])
                j++;
            
            if (needle[j] == '\0')
                return res;
        }
        i++;
    }
    return 0;
}