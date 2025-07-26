/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:34:03 by andcardo          #+#    #+#             */
/*   Updated: 2025/07/26 16:20:47 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	write_line(char **stash, char **line);
static	void	fill_stash(char **stash, char **buffer, int fd);

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	fill_stash(&stash, &buffer, fd);
	if (!stash)
	{
		free(buffer);
		return (NULL);
	}
	write_line(&stash, &line);
	if (!line)
		return (NULL);
	return (line);
}

static	void	fill_stash(char **stash, char **buffer, int fd)
{
	int	bytes_read;

	while (!(*stash) || !ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);

		if (bytes_read <= 0)
		{
			*stash = NULL;
			return;
		}
		(*buffer)[bytes_read] = '\0';
		*stash = ft_strjoin(*stash, *buffer);
	}
}

static void	write_line(char **stash, char **line)
{
	char	*newline_ptr;
	char	*leftovers;
	size_t	line_len;

	newline_ptr = ft_strchr(*stash, '\n');
	line_len = newline_ptr - *stash + 1;
	*line = (char *)malloc((line_len + 1) * sizeof(char));
	ft_memcpy(*line, *stash, line_len);
	(*line)[line_len] = '\0';
	*stash = newline_ptr + 1;
}
