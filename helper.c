#include <stdio.h>
#include <stddef.h>
#include <string.h>

void	separator(char *sentence, char color);
void	print_line(size_t len);
void 	colorize_text(char color);
void 	default_color();


void	separator(char *sentence, char color)
{
	size_t len;

	len = strlen(sentence);
	putchar('\n');
	colorize_text(color);
	print_line(len);
	printf("%s\n", sentence);
	print_line(len);
	default_color();
	putchar('\n');
}

void	print_line(size_t len)
{
	while (len > 0)
	{
		putchar('=');
		len--;
	}
	putchar('\n');
}

void	colorize_text(char color)
{
	putchar('\033');
	putchar('[');
	putchar('0');
	putchar(';');
	putchar('3');
	if (color == 'r')
		putchar('1');
	else if (color == 'g')
		putchar('2');
	else if (color == 'y')
		putchar('3');
	else if (color == 'b')
		putchar('4');
	else if (color == 'm')
		putchar('5');
	else if (color == 'c')
		putchar('6');
	putchar('m');
}

void	default_color()
{
	putchar('\033');
	putchar('[');
	putchar('0');
	putchar('m');
}
