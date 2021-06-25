/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:42:11 by nkim              #+#    #+#             */
/*   Updated: 2021/05/22 18:55:29 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

// char *free_and_strjoin(char *buffer, char *next_sp, char **line)
// {
//     char *tmp;
    
//     tmp = *line;
//     *line = ft_strjoin(*line, ft_strdupptr(buffer, next_sp));
//     free(tmp);
//     tmp = NULL;

//     return tmp;
// }

void    *ft_memset(void *dst, int value, size_t n)
{
    size_t i;
    i = 0;

	while (i < n)
    {
        *((char *)dst+i) = value;
        i++;    
    }
    return dst;
}
int put_line(int fd, char *buffer, char **line, char **file_rest)
{
    char *next_sp;
    int bytes;

    if (!*line && *file_rest)
    {
        *line = ft_strdupchr(*file_rest, 0);
        // *line = ft_strdupchr(*file_rest, '\n');
        // *file_rest = ft_strchr(*file_rest, '\n'); // 나중에 할질말지 확인
        free(*file_rest);
        *file_rest = NULL;
    }
    bytes = 1; 
    next_sp = 0;
    while (!next_sp)
    {
        ft_memset(buffer, 0, BUFFER_SIZE);
        if ((bytes = read(fd, buffer, BUFFER_SIZE)) == -1)
            return -1;
        if (!bytes)
            return 0;
        next_sp = ft_strchr(buffer, '\n'); 
        if (!(*line))
            *line = ft_strdupptr(buffer, next_sp);
        else
            *line = ft_strjoin(*line, ft_strdupptr(buffer, next_sp));
            // free_and_strjoin(buffer, next_sp, line);
    }
    if (next_sp)
        *file_rest = ft_strdupchr(next_sp + 1, 0);
    return 1;
}

int get_next_line(int fd, char **line)
{
    static char *file_rest[256];
    char buffer[BUFFER_SIZE + 1];
    char *next_sp;
    char *ptr;
    int status;

    if (file_rest[fd] && (next_sp = ft_strchr(file_rest[fd], '\n')))
    {
        *line = ft_strdupptr(file_rest[fd], next_sp);
        ptr = file_rest[fd];
        file_rest[fd] = ft_strdupchr(next_sp + 1, 0);
        free(ptr);
        ptr = NULL;
        return 1;
    }
    buffer[BUFFER_SIZE] = '\0';
    *line = 0;
    status = put_line(fd, buffer, line, &(file_rest[fd]));
    if (status == -1)
        return -1;
    else if (status == 0)
    {
        if (!*line)
        {
            *line = (char *)malloc(1);
            (*line)[0] = '\0';
        }
        return 0;
    }
    else
        return 1;
}
//  int main(void)
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