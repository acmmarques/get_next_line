/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:30:02 by andcardo          #+#    #+#             */
/*   Updated: 2025/07/25 23:31:04 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
//TODO: É preciso tirar o stdio daqui antes de entregar e o string tb
# include <stdio.h>
# include <string.h>

char	*get_next_line(int fd);

# define BUFFER_SIZE 42

#endif
