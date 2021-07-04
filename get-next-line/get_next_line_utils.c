/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:25:54 by nkim              #+#    #+#             */
/*   Updated: 2021/07/05 04:01:07 by nkim             ###   ########.fr       */
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

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while (i < n && !flag)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		if (*((unsigned char *)src + i) == (unsigned char)c)
			flag = 1;
		i++;
	}
	if (flag)
		return ((unsigned char *)dst + i);
	else
		return (0);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	len;
// 	char	*res;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1 || !s2)
// 		return (0);
// 	len = ft_strlen(s1) + ft_strlen(s2);
// 	if (!(res = (char *)malloc(len * sizeof(char) + 1)))
// 		return (0);
// 	i = 0 - 1;
// 	while (++i < ft_strlen(s1))
// 		res[i] = s1[i];
// 	j = 0 - 1;
// 	while (i < len)
// 		res[i++] = s2[++j];
// 	res[i] = '\0';
// 	return (res);
// }

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len1;
    size_t len2;
    char *res;

    if (!s1 || !s2)
        return 0;
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    res = (char *)malloc(len1 + len2 + 1);
    ft_memccpy(res, s1, 0, len1);
    ft_memccpy(res + len1, s2, 0, len2);
    res[len1 + len2] = '\0';

    return res;
}

char *ft_strndup(const char *s1, size_t n)
{
    char *res;
    
    res = (char *)malloc(sizeof(char) * (n + 1));
    if (!res)
        return 0;
    ft_memccpy(res, s1, 0, n);
    res[n] = '\0';
    return res;
}

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*res;

	size = ft_strlen(s1);
	if (!(res = malloc(size + 1)))
		return (0);
	size = 0;
	while (s1[size])
	{
		res[size] = s1[size];
		size++;
	}
	res[size] = '\0';
	return (res);
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