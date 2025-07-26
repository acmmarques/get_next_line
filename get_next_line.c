/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:34:03 by andcardo          #+#    #+#             */
/*   Updated: 2025/07/25 23:30:54 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;
	size_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	//TODO: STEP 1
	//Enquanto stash não tiver nova linha,vamos continuar a ler de fd
	while (!strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);

		buffer[bytes_read] = '\0';
	}
	return (stash);
}
