/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:20:18 by andcardo          #+#    #+#             */
/*   Updated: 2025/07/26 10:59:52 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	total_size;
	char	*concat_str;

	len_s1 = 0;
	if (s1)
		len_s1 = ft_strlen(s1);
	len_s2 = 0;
	if (s2) 
		len_s2 = ft_strlen(s2);
	total_size = len_s1 + len_s2;
	concat_str = (char *)malloc(sizeof(char) * (total_size + 1));
	if (!concat_str)
		return (NULL);
	if (s1)
		ft_memcpy(concat_str, s1, len_s1);
	if (s2)
		ft_memcpy(concat_str + len_s1, s2, len_s2);
	concat_str[total_size] = '\0';
	return (concat_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*dest_ptr;
	const unsigned char		*src_ptr;

	if (!dest && !src)
		return (dest);
	dest_ptr = dest;
	src_ptr = src;
	while (n--)
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)&(s[i]));
	return ((char *)0);
}
