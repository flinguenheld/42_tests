#include "get_next_line.h"
#include "fcntl.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Clone just to display the last line without having a leak
char *clone(char *str)
{
	size_t blah = strlen(str);
	char *new = malloc(blah + 1);
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
void test_file_with_backslash0(char *file_name, size_t len)
{
	printf("\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("----------------- Special \\0: ->'%s'<- ---- BUFFER SIZE = %d\n", file_name, BUFFER_SIZE);

	int fd = open(file_name, O_RDONLY);
	int i = 0;
	char *line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break;
		}
		else
		{
			printf("\nStart of a new line ->\n");
			for (int i = 0; i < len; i++)
				printf("%c", line[i]);
			printf("\n<- End of the line\n");
		}
		i++;
	}
}
void real_next_line(char *file_name)
{
	printf("\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("----------------- FGETS : ->'%s'<- ---- BUFFER SIZE = %d\n", file_name, BUFFER_SIZE);

	FILE *file = fopen(file_name, "r");
	if (file != NULL)
	{
		char buffer[100] = "";

		printf("\n");
		while (fgets(buffer, 99, file))
		{
		    printf("%s", buffer);
		}
		fclose(file);

		printf("\n");
		for (int i=0; i< 50; i++)
		{
			printf("%c", buffer[i]);
		}
	}
}

// Test save_ptr & get_ptr
void unit_test_pointers()
{
	char remainder[BUFFER_SIZE + 2 * sizeof(intptr_t)] = "a";
	char *first_text = "This is text to save first\n";
	char *second_text = "Then, another text\n";

	// printf("ADDRESS OF REMAINDER: %p\n", remainder);

	// Firstly get pointers to check they are NULL
	printf("\n");
	printf("pointer has to be null : %p\n", get_ptr(remainder, 0));
	printf("pointer has to be null : %p\n", get_ptr(remainder, 1));
	printf("\n");	

	// Now save the two pointers at the end of remainder
	printf("'save_this_one' address : %p\n", first_text);
	printf("'and_this_one'  address : %p\n", second_text);
	save_ptr(remainder, first_text, 0);
	save_ptr(remainder, second_text, 1);

	// And get them back in a new pointer
	char *ptr_1 = get_ptr(remainder, 0);
	char *ptr_2 = get_ptr(remainder, 1);

	printf("\n");

	printf("First text -------------------------------------\n");
	printf("original ptr : %p\n", first_text);
	printf("pointer got  : %p\n", ptr_1);
	printf("original value : '%s'\n", first_text);
	printf("value got      : '%s'\n", ptr_1);
	printf("\n");	
	
	printf("Second text ------------------------------------\n");
	printf("original ptr : %p\n", second_text);
	printf("pointer got  : %p\n", ptr_2);
	printf("original value : '%s'\n", second_text);
	printf("value got      : '%s'\n", ptr_2);
	printf("\n");	
}


// ./generate_files.sh
// cc -Wall -Wextra -Werror -fsanitize=address *.c *.h -D BUFFER_SIZE=1 && ./a.out
// cc -Wall -Wextra -Werror *.c *.h -D BUFFER_SIZE=1 && valgrind --leak-check=full --show-leak-kinds=all ./a.out
int main()
{
	// unit_test_pointers();


	test_file("raaaa.txt",                                      1);

	// return 0;

	test_file("simple_line.txt",                                      1);
	test_file("simple_line_no_nl.txt",                                1);

	// return 0;

	// test_file("backslash_zero.txt",                                   1);
	// real_next_line("backslash_zero.txt");
	// return 0;

	test_file("no_file.txt",                                          1);
	test_file("empty.txt",                                            1);
	test_file("one_new_line.txt",                                     1);
	test_file("one_tab.txt",                                          1);
	test_file("ten_new_lines.txt",                                    1);
	test_file("ten_new_lines_with_txt_in_the_middle.txt",             1);
	test_file("twenty_lines_one_char.txt",                            1);

	// return 0;

	test_file("multiple_lines.txt",                                   1);
	test_file("multiple_lines_no_last_nl.txt",                        1);
	test_file("multiple_long_lines.txt",                              1);

	// return 0;

	test_file("/etc/passwd",                                          1);

	// return 0;

	test_file_with_backslash0("line_with_one_backslash0.txt", 36);
	test_file_with_backslash0("lines_with_backslash0.txt",    46);

	return 0;

	test_file("long_unique_line.txt",                                 0);
	test_file("long_unique_line_no_nl.txt",                           0);
	test_file("lot_of_lines.txt",                                     0);
	test_file("lot_of_lines_no_last_nl.txt",                          0);


	

	return 0;
}
