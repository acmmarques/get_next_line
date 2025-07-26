/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:15:45 by andcardo          #+#    #+#             */
/*   Updated: 2025/07/26 16:18:14 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h" 

int	main()
{
	int fd = open("tests/single_no_nl_exact.txt",O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
		puts(line);
}
