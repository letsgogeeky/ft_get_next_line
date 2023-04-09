/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:08:04 by ramoussa          #+#    #+#             */
/*   Updated: 2023/04/09 15:32:12 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000000
#endif

static void	free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

static char	*adjust_buffer(char *str)
{
	int		buffer_idx;
	int		new_idx;
	char	*new_buffer;

	buffer_idx = 0;
	if (!str)
		return (free_str(str), NULL);
	while (str[buffer_idx] && str[buffer_idx] != '\n')
		buffer_idx++;
	if (!str[buffer_idx])
		return (free_str(str), NULL);
	new_buffer = ft_calloc(ft_strlen(str) - buffer_idx + 1, sizeof(char));
	if (new_buffer == NULL)
		return (free_str(str), free_str(new_buffer), NULL);
	buffer_idx++;
	new_idx = 0;
	while (str[buffer_idx])
		new_buffer[new_idx++] = str[buffer_idx++];
	new_buffer[new_idx + 1] = 0;
	return (free_str(str), new_buffer);
}

static char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] != '\n')
		line = ft_calloc(i + 1, sizeof(char));
	else
		line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i])
	{
		line[i] = str[i];
		if (line[i] == '\n')
		{
			i++;
			line[i] = 0;
			break ;
		}
		i++;
	}
	return (line);
}

static char	*ft_read_from_fd(int fd, char *str)
{
	int		read_size;
	char	*tmp;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (free_str(str), NULL);
	read_size = read(fd, tmp, BUFFER_SIZE);
	if (read_size == -1)
		return (free_str(tmp), free_str(str), NULL);
	while (read_size > 0)
	{
		tmp[read_size] = '\0';
		if (!str)
			str = ft_calloc(1, sizeof(char));
		str = ft_strjoin(str, tmp);
		if (ft_strchr(str, '\n'))
			break ;
		read_size = read(fd, tmp, BUFFER_SIZE);
		if (read_size == -1)
			return (free_str(tmp), free_str(str), NULL);
	}
	free_str(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (free_str(buffer), buffer = NULL, NULL);
	buffer = ft_read_from_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = adjust_buffer(buffer);
	return (line);
}
