/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:25:54 by nkim              #+#    #+#             */
/*   Updated: 2022/09/18 20:22:55 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == (char)c)
			return ((char *)(&src[i]));
		i++;
	}
	if (c == 0)
		return ((char *)(&src[i]));
	return (0);
}

void	*gnl_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dst <= src)
	{
		while (i < n)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			*((char *)dst + (n - i - 1)) = *((char *)src + (n - i - 1));
			i++;
		}
	}
	return (dst);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1 || !s2)
		return (0);
	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	gnl_memmove(res, s1, len1);
	gnl_memmove(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	return (res);
}

char	*gnl_strndup(const char *s1, size_t n)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (0);
	gnl_memmove(res, s1, n);
	res[n] = '\0';
	return (res);
}
