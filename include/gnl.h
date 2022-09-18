/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:21:50 by nkim              #+#    #+#             */
/*   Updated: 2022/09/18 22:21:47 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl_manager
{
	char	**file_rest;
	char	*line;
	int		max_fd;
}			t_gnl_manager;

size_t		gnl_strlen(const char *s);
void		*gnl_memset(void *dst, int value, size_t n);
char		*gnl_strchr(const char *src, int c);
void		*gnl_memmove(void *dst, const void *src, size_t n);
char		*gnl_strjoin(char const *s1, char const *s2);
char		*gnl_strndup(const char *s1, size_t n);
char		*get_next_line(int fd);

#endif
