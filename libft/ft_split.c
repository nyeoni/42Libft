/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:31:07 by nkim              #+#    #+#             */
/*   Updated: 2021/05/12 21:56:23 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int get_address_cnt(char const *s, char c)
{
    int cnt;

    cnt = 0;
    while (*s)
    {
        if (*(s++) != c)
        {
            cnt++;
            while ((*s != c) && *s)
                s++;
            continue;
        }
        s++;
    }
    return cnt;
}

int *get_string_cnt(char const *s, char c, int address_cnt)
{
    int *res;
    int *tmp;
    int cnt;
    
    if (!(res = (int *)malloc(sizeof(int) * address_cnt)))
        return 0;
    tmp = res;
    while (*s)
    {
        cnt = 0;
        if (*s != c)
        {
            while ((*s != c) && *(s++))
                cnt++;
            *tmp = cnt;
            tmp++;
            continue;
        }
        s++;
    }
    return res;
}

void free_all(char **res)
{
    int i;
    
    i = 0;
    while (res[i])
    {
        free(res[i]);
        res[i] = 0;
        i++;
    }
    free(res);
    res = 0;
}

void put_string(char const *s, char c, char **res)
{
    int i;
    int j;

    i = 0;
    while (*s)
    {
        if (*s != c)
        {
            j = 0;
            while ((*s != c) && *s)
            {
                res[i][j] = *(s++);
                j++;
            }
            i++;
            continue;
        }
        s++;
    }
}

#include <stdio.h>
char **ft_split(char const *s, char c)
{
    char **res;
    int address_cnt;
    int *string_cnt;
    int i;
    
    address_cnt = get_address_cnt(s, c);
    printf("address_cnt : %d\n", address_cnt);
    string_cnt = get_string_cnt(s, c, address_cnt);
    printf("string_cnt : %d\n", string_cnt[0]);
    if(!(res = (char **)malloc(sizeof(char *) * address_cnt)))
        return 0;
    i = 0 - 1;
    while (++i < address_cnt)
    {
        if (!(res[i] = (char *)malloc(sizeof(char) * (string_cnt[i] + 1))))
        {
            free_all(res);
            return 0;
        }
    }
    put_string(s, c, res);
    return res;
}