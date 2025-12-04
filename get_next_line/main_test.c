#include "get_next_line.h"
#include "fcntl.h"
#include <stdio.h>

// Clone just to display the last line without having a leak
char *clone(char *str)
{
	char *new = malloc(length(str) + 1);
	char *start = new;
	while (*str != '\0')
		*new++ = *str++;
	*new = '\0';
	return start;
}

void test_file(char *file_name, char print_lines)
{
	printf("\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("----------------- Try this file: ->'%s'<- ---- BUFFER SIZE = %d\n", file_name, BUFFER_SIZE);

	int fd = open(file_name, O_RDONLY);
	int i = 0;
	char *line = NULL;
	char *last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf("-> %d lines read\n", i);
			printf("-> last one: '%s'\n", last_line);
			break;
		}
		else
		{
			if (print_lines)
				printf("line %d -> '%s'\n", i, line);
			free(last_line);
			last_line = clone(line);
			free(line);
		}
		i++;
	}
	free(last_line);
}

// ./generate_files.sh
// cc -Wall -Wextra -Werror -fsanitize=address *.c *.h -D BUFFER_SIZE=1 && ./a.out
// cc -Wall -Wextra -Werror *.c *.h -D BUFFER_SIZE=1 && valgrind --leak-check=full --show-leak-kinds=all ./a.out
int main()
{

	test_file("simple_line.txt",                                      1);
	test_file("simple_line_no_nl.txt",                                1);

	return 0;

	test_file("no_file.txt",                                          1);
	test_file("empty.txt",                                            1);
	test_file("one_new_line.txt",                                     1);
	test_file("one_tab.txt",                                          1);
	test_file("ten_new_lines.txt",                                    1);
	test_file("ten_new_lines_with_txt_in_the_middle.txt",             1);
	test_file("twenty_lines_one_char.txt",                            1);

	return 0;

	test_file("multiple_lines.txt",                                   1);
	test_file("multiple_lines_no_last_nl.txt",                        1);
	test_file("multiple_long_lines.txt",                              1);

	return 0;

	test_file("/etc/passwd",                                          1);

	return 0;

	test_file("long_unique_line.txt",                                 0);
	test_file("long_unique_line_no_nl.txt",                           0);
	test_file("lot_of_lines.txt",                                     0);
	test_file("lot_of_lines_no_last_nl.txt",                          0);

	return 0;
}
