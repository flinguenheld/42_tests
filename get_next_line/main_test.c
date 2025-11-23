#include "get_next_line.h"
#include <stdio.h>

void test_t_string()
{
	t_string str = str_new(NULL);
	str = str_push_back(str, 'a');
	str = str_push_back(str, 'b');
	str = str_push_back(str, 'c');
	str = str_push_back(str, 'd');
	str = str_push_back(str, 'e');
	str = str_push_back(str, 'f');
	str = str_push_back(str, 'g');
	str = str_push_back(str, 'h');
	str = str_push_back(str, 'i');
	str = str_push_back(str, 'j');

	printf("length: %zu\n", str.length);
	for (size_t i=0; i < str.length; i++)
		printf("%c", str.values[i]);
	printf("\n");

	printf("Add 5000 'a' ---------------------\n");
	for (size_t i=0; i<5000; i++)
		str = str_push_back(str, 'a');

	printf("length: %zu\n", str.length);

	printf("\n");
	printf("Pop them all ---------------------\n");
	while (str.length > 0)
		printf("%c", str_pop_front(&str));
	printf("\nlength: %zu\n", str.length);

	free(str.values);
}

int main()
{
	// test_t_string();
	// return 0;

	// --
	// int fd = open("fail", O_RDONLY);
	// int fd = open("/etc/passwd", O_RDONLY);
	// int fd = open("empty", O_RDONLY);
	// int fd = open("10_without_nl.txt", O_RDONLY);
	// int fd = open("10_with_nl.txt", O_RDONLY);
	// int fd = open("lot_of_lines.txt", O_RDONLY);
	int fd = open("long_line.txt", O_RDONLY);

	// cc -g *.c *.h -fsanitize=address -D BUFFER_SIZE=10 && ./a.out

	// int fd = 0;
	char *line = NULL;

	int line_number = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf("null\n");
			break ;
		}
		else 
			printf("%d -> '%s'", line_number, line);
		free(line);
		line_number++;
	}

	close(fd);
}
