#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h" 
#include "helper.c" 

void	test_file(int fd);
void	test_one_line(int fd);

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 0 || argc > 2)
	{
		printf("Provide a file, please.\n");
		return 0;
	}
	printf("Choose:\n0\tstdin;\n1\tstdoout;\n2\tstderr;\n3\tyour own file;\n4\tjust one line from your own file;\n");
	scanf("%d", &fd);
	if (fd == 0)
	{
		separator("TESTING STDIN", 'g');
		test_one_line(fd);
		return 0;
	}
	else if (fd == 1)
	{
		separator("TESTING STDOUT", 'y');
		test_file(fd);
		return 0;
	}
	else if (fd == 2)
	{
		separator("TESTING STDERR", 'r');
		test_file(fd);
		return 0;
	}
	else if (fd < 1 || fd > 4)
	{
		printf("Error! Insert a valid number, please.\n");
		return 0;
	}
	else if (fd == 3)
	{
		char	filename[256];
		printf("Enter the filename:\n");
		scanf("%s", filename);
		fd = open(filename, O_RDONLY);
		if (fd < 0)
		{
			printf("Error! File doesn't exist. Check name.\n");
			return 0;
		}
		separator("TESTING YOUR OWN FILE", 'g');
		test_file(fd);
	}
	else if (fd == 4)
	{
		char	filename[256];
		printf("Enter the filename:\n");
		scanf("%s", filename);
		fd = open(filename, O_RDONLY);
		if (fd < 0)
		{
			printf("Error! File doesn't exist. Check name.\n");
			return 0;
		}
		separator("TESTING JUST ONE LINE FROM YOUR OWN FILE", 'g');
		test_one_line(fd);
	}


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
	argc += 0;
	argv[1] = "hello";
}

void	test_file(int fd)
{
	char	*line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}

void	test_one_line(int fd)
{
	char	*line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
}
