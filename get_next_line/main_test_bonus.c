#include "get_next_line_bonus.h"
#include "fcntl.h"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

void test_files_bonus(char print_lines, int nb, ...)
{
	char *file_names[nb];
	int file_fd[nb];
	char file_over[nb];
	va_list args;
	va_start(args, nb);

	printf("\x1B[32m---------------------------------------------------------------------------\x1B[0m\n");
	printf("\x1B[32m---------------------------- %d files, randomly read until their ends -----\x1B[0m\n", nb);

	// Get all file names, open them and init 'file_over'
	for (int i=0; i<nb; i++)
	{
		file_names[i] = va_arg(args, char *);
		file_fd[i] = open(file_names[i], O_RDONLY);
		file_over[i] = 0;
		printf("Open file: %s (fd: %d)\n", file_names[i], file_fd[i]);
	}
	va_end(args);
	printf("\n");

	while (1)
	{
		int index = rand() % nb;

		printf("--> Get the next line in \x1B[34m'%s'\x1B[0m (fd: %d)\n", file_names[index], file_fd[index]);
		char *line = get_next_line(file_fd[index]);
		if (line == NULL)
		{
			printf("\x1B[35m-----------> File '%s' is done -------------\x1B[0m\n", file_names[index]);
			file_over[index] = 1;
		}
		else
		{
			if (print_lines)
				printf("\x1B[33m'%s'\x1B[0m\n", line);
			free(line);
		}
		printf("\n");

		// Are all file read ??
		char done = 1;
		for (int i=0; i<nb; i++)
		{
			if (file_over[i] == 0)
			{
				done = 0;
				break;
			}
		}

		if (done)
			break;
	}


	// Close them all
	for (int i=0; i<nb; i++)
	{
		printf("Close file: %s with fd %d\n", file_names[i], file_fd[i]);

		close(file_fd[i]);
	}

}


// ./generate_files.sh
// cc -Wall -Wextra -Werror -fsanitize=address *bonus.c *bonus.h -D BUFFER_SIZE=1 && ./a.out
// cc -Wall -Wextra -Werror *bonus.c *bonus.h -D BUFFER_SIZE=1 && valgrind --leak-check=full --show-leak-kinds=all ./a.out
int main()
{
	srand(time(NULL));

	// Tests with one file from the regular get next line
	test_files_bonus(1, 1, "no_file.txt"                              );
	test_files_bonus(1, 1, "empty.txt"                                );
	test_files_bonus(1, 1, "one_new_line.txt"                         );
	test_files_bonus(1, 1, "one_tab.txt"                              );
	test_files_bonus(1, 1, "ten_new_lines.txt"                        );

	// return 0;

	test_files_bonus(1, 1, "ten_new_lines_with_txt_in_the_middle.txt" );
	test_files_bonus(1, 1, "twenty_lines_one_char.txt"                );

	test_files_bonus(1, 1, "simple_line_no_nl.txt"                    );

	// return 0;

	test_files_bonus(1, 1, "multiple_lines.txt"                       );
	test_files_bonus(1, 1, "multiple_lines_no_last_nl.txt"            );
	test_files_bonus(1, 1, "multiple_long_lines.txt"                  );

	// return 0;

	// Tests with the same file ????
	// It opens the same file but with another file descriptor
	// So it's ok
	test_files_bonus(1, 3, "multiple_lines.txt",
                           "multiple_lines.txt",
                           "multiple_lines.txt" );

	// return 0;

	// One line per file
	test_files_bonus(1, 3, "bonus_simple_file_1.txt",
                           "bonus_simple_file_2.txt",
                           "bonus_simple_file_3.txt" );

	// The second file doesn't exist, so it has to return null has an empty file.
	// The others have to be read (I guess)
	test_files_bonus(1, 3, "bonus_simple_file_1.txt",
                           "NO_FILE.txt",
                           "bonus_simple_file_3.txt" );

	test_files_bonus(1, 1, "/etc/passwd");

	// return 0;

	// Empty files
	test_files_bonus(1, 3, "bonus_empty_file_1.txt",
                           "bonus_empty_file_2.txt",
                           "bonus_empty_file_3.txt" );

	// 10 lines in 10 files
	test_files_bonus(1, 10, "bonus_10_lines_file_1.txt",
                            "bonus_10_lines_file_2.txt",
                            "bonus_10_lines_file_3.txt",
                            "bonus_10_lines_file_4.txt",
                            "bonus_10_lines_file_5.txt",
                            "bonus_10_lines_file_6.txt",
                            "bonus_10_lines_file_7.txt",
                            "bonus_10_lines_file_8.txt",
                            "bonus_10_lines_file_9.txt",
                            "bonus_10_lines_file_10.txt" );

	// 3 lines an a long one in 10 files and no new line at the end
	test_files_bonus(1, 10, "bonus_10_long_lines_file_1.txt",
                            "bonus_10_long_lines_file_2.txt",
                            "bonus_10_long_lines_file_3.txt",
                            "bonus_10_long_lines_file_4.txt",
                            "bonus_10_long_lines_file_5.txt",
                            "bonus_10_long_lines_file_6.txt",
                            "bonus_10_long_lines_file_7.txt",
                            "bonus_10_long_lines_file_8.txt",
                            "bonus_10_long_lines_file_9.txt",
                            "bonus_10_long_lines_file_10.txt" );
}
