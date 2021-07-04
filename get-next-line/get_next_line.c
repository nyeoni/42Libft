/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:42:11 by nkim              #+#    #+#             */
/*   Updated: 2021/07/05 05:07:27 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	*ft_memset(void *dst, int value, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)dst + i) = value;
		i++;
	}
	return (dst);
}

void free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	manage_line(char **line, char **file_rest)
{
	char *next_sp;
	char *tmp;

	next_sp = ft_strchr(*line, '\n');
	// printf("buffer: %s\n", buffer);

	tmp = ft_strndup(*line, next_sp - *line);	

	if (*file_rest)
		free_ptr(file_rest);
	*file_rest = ft_strndup(next_sp + 1, ft_strlen(next_sp + 1));
	free_ptr(line);
	*line = tmp;
}

int		put_line(int fd, char *buffer, char **line, char **file_rest)
{
	char	*next_sp;
	int		bytes;

	if (!*line && *file_rest)
	{
		*line = ft_strdup(*file_rest);
		free(*file_rest);
		*file_rest = NULL;
	}
	next_sp = 0;
	while (!next_sp)
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		if ((bytes = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		if (!bytes)
			return (0);
		next_sp = ft_strchr(buffer, '\n');
		if (!(*line))
			*line = ft_strdupptr(buffer, next_sp);
		else
			*line = ft_strjoin(*line, ft_strdupptr(buffer, next_sp));
	}
	*file_rest = ft_strdup(next_sp + 1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*file_rest[256];
	char		buffer[BUFFER_SIZE + 1];
	int	r_bytes;
	// char		*next_sp;
	// char		*ptr;
	// int			status;

	if (fd < 0 || fd >= 256 || !line)
		return -1; // 나중에 확인해보기
	
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	*line = NULL;
	if (file_rest[fd])
	{
		ft_memccpy(buffer, file_rest[fd], 0, ft_strlen(file_rest[fd]));
		free_ptr(&file_rest[fd]);
	}
		
	if (!*line)
		*line = ft_strndup(buffer, ft_strlen(buffer));
	while (!(ft_strchr(buffer, '\n')))
	{		
		ft_memset(buffer, 0, BUFFER_SIZE);
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes == -1)
			return -1;
		else if (r_bytes == 0)
			return 0;
		*line = ft_strjoin(*line, buffer);
	}
	// 결과 도출해주는 함수
	// manage_line 으로 가는 경우 : 1. \n 을 찾았을 때 2. fd 를 읽었을 때 0이 나왔을 경우
	manage_line(line, &(file_rest[fd]));
	return 1;

	// if (file_rest[fd] && (next_sp = ft_strchr(file_rest[fd], '\n')))
	// {
	// 	*line = ft_strdupptr(file_rest[fd], next_sp);
	// 	ptr = file_rest[fd];
	// 	file_rest[fd] = ft_strdup(next_sp + 1);
	// 	free(ptr);
	// 	ptr = NULL;
	// 	return (1);
	// }
	// *line = 0;
	// status = put_line(fd, buffer, line, &(file_rest[fd]));
	// if (status == -1)
	// 	return (-1);
	// else if (status == 0)
	// {
	// 	if (!*line)
	// 	{
	// 		*line = (char *)malloc(1);
	// 		(*line)[0] = '\0';
	// 	}
	// 	return (0);
	// }
	// else
	// 	return (1);
}

// int main(void)
// {
//     int fd = open("fuck.txt", O_RDONLY);
//     char *tmp;
//     int res;

//     while ((res = get_next_line(fd, &tmp)) > 0)
//     {
//         printf("%2d-%s\n", res, tmp);
//     }
//     printf("%2d-%s\n", res, tmp);
//     // printf("res : %d\n", res);
// }