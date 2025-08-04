/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:20:18 by andcardo          #+#    #+#             */
/*   Updated: 2025/08/04 09:40:03 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char *strjoin_n_free_gnl(char *s1, char *s2)
{
    char    *concat_str;
    size_t  s1_len;
    size_t  s2_copylen;
    size_t  i;
    size_t  j;

    if (!s1 || !s2)
        return (NULL);
    s2_copylen = 0;
    while (s2[s2_copylen] && s2[s2_copylen] != '\n')
        s2_copylen++;
    if (s2[s2_copylen] == '\n')
        s2_copylen++;
	s1_len = ft_strlen(s1);
    concat_str = malloc(s1_len + s2_copylen + 1);
    if (!concat_str)
        return (free(s1), NULL);
    i = -1;
    while (++i < s1_len)
        concat_str[i] = s1[i];
    j = -1;
    while (++j < s2_copylen)
        concat_str[i + j] = s2[j];
    concat_str[i + j] = '\0';
    free(s1);
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

char	*ft_strdup(char *s1)
{
	char	*cpy_str;
	size_t	i;

	if (!s1)
		return (NULL);
	cpy_str = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!cpy_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy_str[i] = s1[i];
		i++;
	}
	cpy_str[i] = '\0';
	return (cpy_str);
}

void clean_buffer(char *buffer)
{
	char    *nl_ptr;
	size_t  i;

	nl_ptr = ft_strchr(buffer, '\n');
	if (!nl_ptr)
	{
		buffer[0] = '\0';
		return;
	}
	if (!*(nl_ptr + 1))
	{
		buffer[0] = '\0';
		return;
	}
	i = 0;
	while ((nl_ptr)[i + 1])
	{
		buffer[i] = (nl_ptr)[i + 1];
		i++;
	}
	buffer[i] = '\0';
}
