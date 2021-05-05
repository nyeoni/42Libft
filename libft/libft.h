/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:54:36 by nkim              #+#    #+#             */
/*   Updated: 2021/05/05 21:34:24 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned long	size_t;

size_t ft_strlen(const char *s);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
char *ft_strdup(const char *s1);
char *ft_strchr(const char *src, int c);
void    *ft_memset(void *dst, int value, size_t n);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memmove(void *dst, void *src, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memchr(const void *src, int c, size_t n);
void *ft_memccpy(void *dst, const void *src, int c, size_t n);
void *ft_calloc(size_t count, size_t size);
void ft_bzero(void *src, size_t n);