/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:34:03 by andcardo          #+#    #+#             */
/*   Updated: 2025/07/31 09:47:08 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*stash;
	char		*new_line;
	ssize_t		bytes_read;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		stash = str_join_n_free(stash, buffer);
		if (ft_strchr(buffer, '\n') || bytes_read == 0)
			break;
	}
	if (bytes_read < 0)
		//tem de se dar free tbm na new_line?
		return(free(stash), NULL); 
	if (stash)
		build_line(&new_line, &stash);
	return (new_line);
}
