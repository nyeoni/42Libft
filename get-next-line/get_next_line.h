#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <unistd.h>

size_t ft_strlen(const char *s);
char *ft_strchr(const char *src, int c);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdupchr(char *src, int c);
char *ft_strdupptr(char *src, void *ptr);

int get_next_line(int fd, char **line);

#endif