/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:34:03 by andcardo          #+#    #+#             */
/*   Updated: 2025/08/04 09:49:19 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*new_line;
	ssize_t		bytes_read;

	new_line = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0 || !new_line)
		return (free(new_line), NULL);
	while (1 == 1)
	{
		if (!*buffer)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0 || (bytes_read == 0 && !*new_line))
				return (free(new_line), NULL);
			if (bytes_read == 0)
				return (new_line);
			buffer[bytes_read] = '\0';
		}
		new_line = strjoin_n_free_gnl(new_line, buffer);
		if (!new_line)
			return (NULL);
		if (ft_strchr(new_line, '\n'))
			return (clean_buffer(buffer), new_line);
		buffer[0] = '\0';
	}
}
