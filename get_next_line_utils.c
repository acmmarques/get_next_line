/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:20:18 by andcardo          #+#    #+#             */
/*   Updated: 2025/07/31 09:48:55 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//TODO: tirar esta library
#include <stdio.h>

size_t	strlen_nl(char *s)
{
	size_t i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*str_join_n_free(char *line, char *stash)
{
	char	*concat_str;
	size_t	total_size;
	ssize_t	i;
	ssize_t	j;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	total_size = strlen_nl(line) + strlen_nl(stash);
	concat_str = malloc((total_size + 1) * sizeof(char));
	if (concat_str)
	{
		i = -1;
		j = -1;
		while (line[++i])
			concat_str[i] = line[i];
		while (stash[++j])
			concat_str[i + j] = stash[j];
		concat_str[i + j] = '\0';
	}
	free(line);
	return (concat_str);
}

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return str;
		str++;
	}
	if (*str == '\0' && c == '\0')
		return str;
	return (NULL);
}

void	build_line(char **line, char **stash)
{
	size_t	i;
	char	*nl_char;
	char	*new_stash;

	nl_char = ft_strchr(*stash, '\n');
	if (nl_char)
		nl_char += 1;
	else
		nl_char = ft_strchr(*stash, '\0');
	new_stash = str_join_n_free(NULL, nl_char);
	nl_char[0] = '\0';
	*line = str_join_n_free(NULL, *stash);
	free(*stash);
	*stash = new_stash;
}
