/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:20:26 by nkim              #+#    #+#             */
/*   Updated: 2021/05/07 18:30:24 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int get_first_index(char const *s1, char const *set)
{
    int i;
    int j;
    int flag;

    i = 0;
    while (s1[i])
    {
        flag = 0;
        j = 0 - 1;
        while (set[++j])
        {
            if (set[j] == s1[i])
                flag = 1;
        }
        if (!flag)
            return i;
        i++;
    }
    return -1;
}

int get_last_index(char const *s1, char const *set)
{
    int i;
    int j;
    int flag;

    i = (int) ft_strlen(s1) - 1;
    while (s1[i])
    {
        flag = 0;
        j = 0 - 1;
        while (set[++j])
        {
            if (set[j] == s1[i])
                flag = 1;
        }
        if (!flag)
            return i;
        i--;
    }
    return -1;
}

char *ft_strtrim(char const *s1, char const *set)
{
    int start;
    int last;
    int i;
    char *res;

    if (!s1)
        return 0;

    start = get_first_index(s1, set);
    last = get_last_index(s1, set);
    if (!(res = ft_calloc(last - start + 2, sizeof(char))))
        return 0;
    if (start == -1)
    {
        res[0] = '\0';
        return res;
    }
    i = 0;
    while (start + i <= last)
    {
        res[i] = s1[start + i];
        i++;
    }
    res[i] = '\0';
    return res;
}