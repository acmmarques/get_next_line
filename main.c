#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h" 

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	fd = open("tests/long_file.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);

	argc += 0;
	argv[1] = "hello";

	/*
	 ==Proof that char *buffer[BUFFER_SIZE] can be used.==

	 The norm forbids the usage of Variable Length
	 Arrays - VLAs, for short. But char *buffer is
	 actually a fixed-sized array.

	 VLA are arrays whose length is defined at run time.
	 Fixed-sized arrays have their length defined at
	 compile time. To check that char *buffer[BUFFER_SIZE]
	 is a fixed-sized array we have to take into account 
	 that BUFFER_SIZE is a macro. A macro is a preprocessor
	 directive, i.e., it is going to be taken care of before
	 compilation. Which means that by compile time,
	 BUFFER_SIZE is already defined.

	 We can can prove that by uncomenting the lines below
	 and compiling this main with the -E flag.
	char *fixed_array[BUFFER_SIZE];
	char *vla(argc);
	*/
}
