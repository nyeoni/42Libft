/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:42:11 by nkim              #+#    #+#             */
/*   Updated: 2021/07/24 23:09:41 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	manage_line(char **line, char **file_rest, int r_bytes)
{
	char	*next_sp;
	char	*tmp;

	if (r_bytes == -1 || (r_bytes == 0 && !(*line)[0]))
	{
		free(*line);
		*line = 0;
		return ;
	}
	if (*file_rest)
	{
		free(*file_rest);
		*file_rest = NULL;
	}
	next_sp = ft_strchr(*line, '\n');
	if (next_sp)
	{
		*file_rest = ft_strndup(next_sp + 1, ft_strlen(next_sp + 1));
		if (*line)
		{
			tmp = *line;
			*line = ft_strndup(*line, next_sp - *line + 1);
			free(tmp);
		}
	}
}

char	*set_buffer_line(char *buffer, char **file_rest)
{
	char	*line;

	line = NULL;
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	if (*file_rest)
	{
		ft_memccpy(buffer, *file_rest, 0, ft_strlen(*file_rest));
		free(*file_rest);
		*file_rest = NULL;
	}
	line = ft_strndup(buffer, ft_strlen(buffer));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*file_rest[256];
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	char		*line;
	int			r_bytes;

	if (fd < 0 || fd >= 256 || BUFFER_SIZE <= 0)
		return (0);
	line = set_buffer_line(&buffer[0], &file_rest[fd]);
	while (!(ft_strchr(buffer, '\n')))
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes == -1 || r_bytes == 0)
			break ;
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
	}
	manage_line(&line, &(file_rest[fd]), r_bytes);
	return (line);
}
