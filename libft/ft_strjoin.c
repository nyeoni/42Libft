/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:00:36 by nkim              #+#    #+#             */
/*   Updated: 2021/05/07 18:07:20 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len;
    char *res;
    size_t i;
    size_t j;

    if (!s1 || !s2)
        return 0;
    len = ft_strlen(s1) + ft_strlen(s2);
    if(!(res = ft_calloc(len + 1, sizeof(char))))
        return 0;
    i = 0 - 1;
    while (++i < ft_strlen(s1))
        res[i] = s1[i];
    j = 0 - 1;
    while (i < len)
        res[i++] = s2[++j];
    res[i] = '\0';

    return res;
}

// #include <stdio.h>
// int main(void)
// {
//     char *s1 = "abcd";
//     char *s2 = "efgh";
//     char *res = ft_strjoin(s1, s2);
//     printf("%s\n", res);
// }