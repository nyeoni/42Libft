/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:25:54 by nkim              #+#    #+#             */
/*   Updated: 2021/05/22 17:17:17 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t ft_strlen(const char *s)
{
    size_t len;
    len = 0;

    while (s[len])
        len++;
    
    return len;
}

char *ft_strchr(const char *src, int c)
{
    int i;
    i = 0;
    
    while (src[i])
    {
        if (src[i] == (char)c)
            return (char *)(&src[i]);
        i++;
    }
    if (c == 0)
        return (char *)(&src[i]);
        
    return 0;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len;
    char *res;
    size_t i;
    size_t j;

    if (!s1 || !s2)
        return 0;
    len = ft_strlen(s1) + ft_strlen(s2);
    
    if(!(res = malloc(sizeof(char) * (len + 1))))
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

char *ft_strdupchr(char *src, int c)
{
    char *res;
    int len;
    int i;

    len = 0;
    i = 0;
    while (src[i] != (char)c && src[i]) 
    {
        len++;
        i++;
    }
    res = (char *)malloc(sizeof(char) * (len + 1));
    if (!res)
        return 0;
    res[len] = '\0';
    i = 0;
    while (src[i] != (char)c && src[i])
    {
        res[i] = src[i];
        i++;
    }
    return res;
}

char *ft_strdupptr(char *src, void *ptr)
{
    char *res;
    int len;
    int i;

    len = 0;
    i = 0;
    while (&src[i] != ptr && src[i]) 
    {
        len++;
        i++;
    }
    res = (char *)malloc(sizeof(char) * (len + 1));
    if (!res)
        return 0;
    res[len] = '\0';
    i = 0;
    while (&src[i] != ptr && src[i])
    {
        res[i] = src[i];
        i++;
    }
    return res;
}