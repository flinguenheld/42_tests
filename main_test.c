/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:31:17 by flinguen          #+#    #+#             */
/*   Updated: 2025/11/17 21:51:46 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>
#include <string.h>

char function_strmapi(unsigned int v, char c)
{
	if (c >= 'a' && c <= 'z')
		return ('A' + v);
	else if (c >= 'A' && c <= 'Z')
		return ('a' + v);
	else
		return ('a' + v);
}

void function_striteri(unsigned int v, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = ('A' + v);
	else if (*c >= 'A' && *c <= 'Z')
		*c = ('a' + v);
	else
		*c = ('a' + v);
}

void function_delone(void *content)
{
	// printf("From function del one: free the content\n");
	if (content != NULL)
	{
		free(content);
		content = NULL;
	}
}

void function_lstiter(void *content)
{
	// printf("apply function lstiter\n");
	ft_striteri((char *)content, &function_striteri);
}

void *function_lst_map_clone_only_even(void *content)
{
	if (ft_atoi((char *)content) % 2 == 0)
		return (void *)(ft_strdup((char *)content));
	return NULL;
}

int main(void)
{
	printf("\n################################################## IS_    ###\n");
	for (int i=0; i<255; i++)
	{
		// if (ft_isalpha(i))
		// 	printf("%c is alpha\n", i);
		// if (ft_isdigit(i))
		// 	printf("%c is digit\n", i);
		// if (ft_isalnum(i))
		// 	printf("%c is alnum\n", i);
		// if (ft_isascii(i))
		// 	printf("%c is ascii\n", i);
	}

	printf("\n################################################## STRLEN ###\n");
	printf("'' -> %zu\n", ft_strlen(""));
	printf("'a' -> %zu\n", ft_strlen("a"));
	printf("'abcdefghijklmnopqrstuvwxyz' -> %zu\n", ft_strlen("abcdefghijklmnopqrstuvwxyz"));

	#define STRLEN_LEN 1000000
	// #define STRLEN_LEN 10000000 // Segfault with the real and mine
	char txt_strlen[STRLEN_LEN];
	ft_memset(txt_strlen, 'a', STRLEN_LEN);
	printf("%d -> %zu\n", STRLEN_LEN, strlen(txt_strlen));

	printf("\n################################################## MEMSET ###\n");
	// The real funct doesn't check nb_to_set
	// Nor the tab, it can be empty

	#define TAB_LEN_MEMSET 5
	const int value_to_set_memset = 0;
	const size_t nb_to_set_memset = 3;

	int tab_memset[TAB_LEN_MEMSET] = {10, 11, 12, 14, 15};
	int tab_memset_real[TAB_LEN_MEMSET] = {10, 11, 12, 14, 15};
	// int tab_memset[TAB_LEN_MEMSET] = {};
	// int tab_memset_real[TAB_LEN_MEMSET] = {};

	for (int i=0; i < TAB_LEN_MEMSET; i++)
		printf("%d ", tab_memset[i]);
	
	printf("\n");
	int *set = ft_memset((void *)tab_memset, value_to_set_memset, nb_to_set_memset * sizeof(int));
	for (int i=0; i < TAB_LEN_MEMSET; i++)
		printf("%d ", set[i]);

	printf("\n##################### MEMSET REAL ###\n");
	for (int i=0; i < TAB_LEN_MEMSET; i++)
		printf("%d ", tab_memset_real[i]);
	
	printf("\n");
	int *set_real = memset((void *)tab_memset_real, value_to_set_memset, nb_to_set_memset * sizeof(int));
	for (int i=0; i < TAB_LEN_MEMSET; i++)
		printf("%d ", set_real[i]);

	printf("\n################################################## BZERO ####\n");
	#define TAB_LEN_BZERO 5
	const size_t nb_to_set_bzero = 3;

	int tab_bzero[TAB_LEN_BZERO] = {10, 11, 12, 14, 15};
	int tab_bzero_real[TAB_LEN_BZERO] = {10, 11, 12, 14, 15};
	// int tab_bzero[TAB_LEN_BZERO] = {};
	// int tab_bzero_real[TAB_LEN_BZERO] = {};

	for (int i=0; i < TAB_LEN_BZERO; i++)
		printf("%d ", tab_bzero[i]);

	printf("\n");
	ft_bzero((void *)tab_bzero, nb_to_set_bzero * sizeof(int));
	for (int i=0; i < TAB_LEN_BZERO; i++)
		printf("%d ", tab_bzero[i]);

	printf("\n###################### BZERO REAL ###\n");
	for (int i=0; i < TAB_LEN_BZERO; i++)
		printf("%d ", tab_bzero_real[i]);

	printf("\n");
	bzero((void *)tab_bzero_real, nb_to_set_bzero * sizeof(int));
	for (int i=0; i < TAB_LEN_BZERO; i++)
		printf("%d ", tab_bzero_real[i]);

	printf("\n################################################## MEMCPY ###\n");
	#define TAB_LEN_MEMCPY 5
	const size_t nb_to_memcpy = 1;

	int tab_memcpy_src[TAB_LEN_MEMCPY] = {10, 11, 12, 14, 15};
	int tab_memcpy_dst[TAB_LEN_MEMCPY] = {0, 0, 0, 0, 0};
	int tab_memcpy_dst_real[TAB_LEN_MEMCPY] = {0, 0, 0, 0, 0};

	printf("src: ");
	for (int i=0; i < TAB_LEN_MEMCPY; i++)
		printf("%d ", tab_memcpy_src[i]);
	printf("\ndst: ");
	for (int i=0; i < TAB_LEN_MEMCPY; i++)
		printf("%d ", tab_memcpy_dst[i]);

	printf("\n ->  ");
	ft_memcpy((void *)tab_memcpy_dst, (void *)tab_memcpy_src, nb_to_memcpy * sizeof(int));
	for (int i=0; i < TAB_LEN_MEMCPY; i++)
		printf("%d ", tab_memcpy_dst[i]);

	printf("\n###################### MEMCPY REAL ###\n");
	printf(" ->  ");
	memcpy((void *)tab_memcpy_dst_real, (void *)tab_memcpy_src, nb_to_memcpy * sizeof(int));
	for (int i=0; i < TAB_LEN_MEMCPY; i++)
		printf("%d ", tab_memcpy_dst_real[i]);

	printf("\n###################################### MEMMOVE DEST < SRC ###\n");
	#define TAB_LEN_MEMMOVE 15
	const size_t nb_to_memmove = 5;
	const int gap_memmove = 2;

	int tab_memmove1[TAB_LEN_MEMMOVE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	int tab_memmove2[TAB_LEN_MEMMOVE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	for (int i=0; i < TAB_LEN_MEMMOVE; i++)
		printf("%d ", tab_memmove1[i]);

	printf("\n");
	printf("nb to move: %zu\n", nb_to_memmove);
	printf("gap from source to dest: %d\n", gap_memmove);
	printf("\n");

	ft_memmove((void *)(tab_memmove1), (void *)(tab_memmove1 + gap_memmove), nb_to_memmove * sizeof(int));

	for (int i=0; i < TAB_LEN_MEMMOVE; i++)
		printf("%d ", tab_memmove1[i]);

	printf("\n###################### MEMMOVE REAL ###\n");
	memmove((void *)(tab_memmove2), (void *)(tab_memmove2 + gap_memmove), nb_to_memmove * sizeof(int));

	for (int i=0; i < TAB_LEN_MEMMOVE; i++)
		printf("%d ", tab_memmove2[i]);

	printf("\n###################################### MEMMOVE DEST > SRC ###\n");
	#define TAB_LEN_MEMMOVE 15
	const size_t nb_to_memmove_rev = 5;
	const int gap_memmove_rev = 2;

	int tab_memmove_rev_1[TAB_LEN_MEMMOVE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	int tab_memmove_rev_2[TAB_LEN_MEMMOVE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	for (int i=0; i < TAB_LEN_MEMMOVE; i++)
		printf("%d ", tab_memmove_rev_1[i]);

	printf("\n");
	printf("nb to move: %zu\n", nb_to_memmove_rev);
	printf("gap from source to dest: %d\n", gap_memmove_rev);
	printf("\n");

	ft_memmove((void *)(tab_memmove_rev_1 + gap_memmove_rev), (void *)(tab_memmove_rev_1), nb_to_memmove_rev * sizeof(int));

	for (int i=0; i < TAB_LEN_MEMMOVE; i++)
		printf("%d ", tab_memmove_rev_1[i]);

	printf("\n###################### MEMMOVE REAL ###\n");
	memmove((void *)(tab_memmove_rev_2 + gap_memmove_rev), (void *)(tab_memmove_rev_2), nb_to_memmove_rev * sizeof(int));

	for (int i=0; i < TAB_LEN_MEMMOVE; i++)
		printf("%d ", tab_memmove_rev_2[i]);

	printf("\n################################################# STRLCPY ###\n");
	// TO_COPY_STRLCPY cannot be higher than the buffer size !
	// Otherwise, it destroys the next chars
	#define BUFFER_SIZE_STRLCPY 5
	#define TO_COPY_STRLCPY 5
	char *src_strlcpy = "abcdefghij";

	char dst_strlcpy[BUFFER_SIZE_STRLCPY];
	char dst_strlcpy_real[BUFFER_SIZE_STRLCPY];

	size_t amount_strlcpy = ft_strlcpy(dst_strlcpy, src_strlcpy, TO_COPY_STRLCPY);
	printf("-> %zu -> '%s'", amount_strlcpy, dst_strlcpy);

	printf("\n###################### STRLCPY REAL ###\n");

	size_t amount_strlcpy_real = strlcpy(dst_strlcpy_real, src_strlcpy, TO_COPY_STRLCPY);
	printf("-> %zu -> '%s'", amount_strlcpy_real, dst_strlcpy_real);

	printf("\n################################################# STRLCAT ###\n");
	#define BUFFER_SIZE_STRLCAT 100
	#define TO_COPY_STRLCAT 0
	// char *src_strlcat = "abcdefgh";
	char *src_strlcat = "AAAAAAAAA";

	char dst_strlcat[BUFFER_SIZE_STRLCAT] = "start";
	char dst_strlcat_real[BUFFER_SIZE_STRLCAT] = "start";

	size_t amount_strlcat = ft_strlcat(dst_strlcat, src_strlcat, TO_COPY_STRLCAT);
	printf("-> %zu -> '%s'", amount_strlcat, dst_strlcat);

	printf("\n###################### STRLCAT REAL ###\n");

	size_t amount_strlcat_real = strlcat(dst_strlcat_real, src_strlcat, TO_COPY_STRLCAT);
	printf("-> %zu -> '%s'", amount_strlcat_real, dst_strlcat_real);

	printf("\n##### MINE #################### REAL #############\n");

	char * strlcat_000 = NULL;
	size_t strlcat_000_value = ft_strlcat(strlcat_000, "aaaaa", 0);
	char * strlcat_000_real = NULL;
	size_t strlcat_000_real_value = strlcat(strlcat_000_real, "aaaaa", 0);
	printf("000 -> %zu '%s'          %zu '%s'\n", strlcat_000_value, strlcat_000, strlcat_000_real_value, strlcat_000_real);

	char strlcat_break0_001[100];
	char strlcat_001[10] = "start";
	size_t strlcat_001_value = ft_strlcat(strlcat_001, "bbb", 10);
	char strlcat_break1_001[100];
	char strlcat_001_real[10] = "start";
	size_t strlcat_001_real_value = strlcat(strlcat_001_real, "bbb", 10);
	printf("001 -> %zu '%s'          %zu '%s'\n", strlcat_001_value, strlcat_001, strlcat_001_real_value, strlcat_001_real);

	char strlcat_break0_002[100];
	char strlcat_002[10] = "start";
	size_t strlcat_002_value = ft_strlcat(strlcat_002, "", 10);
	char strlcat_break1_002[100];
	char strlcat_002_real[10] = "start";
	size_t strlcat_002_real_value = strlcat(strlcat_002_real, "", 10);
	printf("002 -> %zu '%s'          %zu '%s'\n", strlcat_002_value, strlcat_002, strlcat_002_real_value, strlcat_002_real);

	char strlcat_break0_003[100];
	char strlcat_003[10] = "";
	size_t strlcat_003_value = ft_strlcat(strlcat_003, "bbb", 10);
	char strlcat_break1_003[100];
	char strlcat_003_real[10] = "";
	size_t strlcat_003_real_value = strlcat(strlcat_003_real, "bbb", 10);
	printf("003 -> %zu '%s'          %zu '%s'\n", strlcat_003_value, strlcat_003, strlcat_003_real_value, strlcat_003_real);

	char strlcat_break0_004[100];
	char strlcat_004[0];
	size_t strlcat_004_value = ft_strlcat(strlcat_004, "bbb", 10);
	char strlcat_break1_004[100];
	char strlcat_004_real[0];
	size_t strlcat_004_real_value = strlcat(strlcat_004_real, "bbb", 10);
	printf("004 -> %zu '%s'          %zu '%s'\n", strlcat_004_value, strlcat_004, strlcat_004_real_value, strlcat_004_real);

	char strlcat_break0_005[100];
	char strlcat_005[50] = "start";
	size_t strlcat_005_value = ft_strlcat(strlcat_005, "bbb", 0);
	char strlcat_break1_005[100];
	char strlcat_005_real[50] = "start";
	size_t strlcat_005_real_value = strlcat(strlcat_005_real, "bbb", 0);
	printf("005 -> %zu '%s'          %zu '%s'\n", strlcat_005_value, strlcat_005, strlcat_005_real_value, strlcat_005_real);

	char strlcat_break0_006[100];
	char strlcat_006[50] = "rrrrrrrrrrrrrrr";
	size_t strlcat_006_value = ft_strlcat(strlcat_006, "lorem ipsum dolor sit amet", 5);
	char strlcat_break1_006[100];
	char strlcat_006_real[50] = "rrrrrrrrrrrrrrr";
	size_t strlcat_006_real_value = strlcat(strlcat_006_real, "lorem ipsum dolor sit amet", 5);
	printf("006 -> %zu '%s'          %zu '%s'\n", strlcat_006_value, strlcat_006, strlcat_006_real_value, strlcat_006_real);


	// Has to fail with two NULL
	// size_t strlcat_006_value = ft_strlcat(NULL, NULL, 3);
	// size_t strlcat_006_real_value = strlcat(NULL, NULL, 3);

	printf("\n################################################# TOUPPER ###\n");
	printf("a -> %c\n", ft_toupper('a'));
	printf("x -> %c\n", ft_toupper('x'));
	printf("A -> %c\n", ft_toupper('A'));
	printf("X -> %c\n", ft_toupper('X'));
	printf("2 -> %c\n", ft_toupper('2'));

	printf("\n################################################# TOLOWER ###\n");
	printf("a -> %c\n", ft_tolower('a'));
	printf("x -> %c\n", ft_tolower('x'));
	printf("A -> %c\n", ft_tolower('A'));
	printf("X -> %c\n", ft_tolower('X'));
	printf("2 -> %c\n", ft_tolower('2'));

	printf("\n################################################## STRCHR ###\n");
	char *str_strchr = "wind hello world";

	printf("\n##### MINE #################### REAL #############\n");
	printf("\t'%s'\t'%s'\n", ft_strchr(str_strchr, 'w'),  strchr(str_strchr, 'w'));
	printf("\t'%s'\t'%s'\n", ft_strchr(str_strchr, 'o'),  strchr(str_strchr, 'o'));
	printf("\t'%s'\t'%s'\n", ft_strchr(str_strchr, 'U'),  strchr(str_strchr, 'U'));
	printf("\t'%s'\t'%s'\n", ft_strchr("",         '\0'), strchr(""        , '\0'));
	printf("\t'%s'\t'%s'\n", ft_strchr("aaaa",     '\0'), strchr("aaaa"    , '\0'));
	printf("\t'%s'\t'%s'\n", ft_strchr("tripouille"    , 't' + 256), strchr("tripouille"    , 't' + 256));
	printf("\t'%s'\t'%s'\n", ft_strchr("teste", 1024), strchr("teste", 1024));

	printf("\n################################################# STRRCHR ###\n");
	char *str_strrchr = "wind hello world";
	// char *str_strrchr = "0123456789";

	printf("\n##### MINE #################### REAL #############\n");
	printf("\t'%s'\t'%s'\n", ft_strrchr(str_strrchr, 'w'),  strrchr(str_strrchr, 'w'));
	printf("\t'%s'\t'%s'\n", ft_strrchr(str_strrchr, 'o'),  strrchr(str_strrchr, 'o'));
	printf("\t'%s'\t'%s'\n", ft_strrchr(str_strrchr, 'U'),  strrchr(str_strrchr, 'U'));
	printf("\t'%s'\t'%s'\n", ft_strrchr("",          '\0'), strrchr("",          '\0'));
	printf("\t'%s'\t'%s'\n", ft_strrchr("aaaa",      '\0'), strrchr("aaaa",      '\0'));
	printf("\t'%s'\t'%s'\n", ft_strrchr("a",         '\0'), strrchr("a",         '\0'));

	char str_strrchr002[300000];
	ft_memset(str_strrchr002, 'a', 299999);
	printf("\t'%s'\t'%s'\n", ft_strrchr(str_strrchr002, 'a'), strrchr(str_strrchr002, 'a'));
	// char *str_strrchr = "0123456789";

	printf("\n################################################# STRNCMP ###\n");
	size_t n_strncmp = 200;

	printf("\n### MINE ###### REAL #############\n");
	printf("\t'%d'\t'%d'\n", ft_strncmp("hello", "hello",   n_strncmp), strncmp("hello", "hello",   n_strncmp));
	printf("\t'%d'\t'%d'\n", ft_strncmp("hello", "hello\n", n_strncmp), strncmp("hello", "hello\n", n_strncmp));
	printf("\t'%d'\t'%d'\n", ft_strncmp("hello", "helloa",  n_strncmp), strncmp("hello", "helloa",  n_strncmp));
	printf("\t'%d'\t'%d'\n", ft_strncmp("aab", "aaa",       n_strncmp), strncmp("aab", "aaa",       n_strncmp));
	printf("\t'%d'\t'%d'\n", ft_strncmp("aab", "",          n_strncmp), strncmp("aab", "",          n_strncmp));
	printf("\t'%d'\t'%d'\n", ft_strncmp("", "bbb",          n_strncmp), strncmp("", "bbb",          n_strncmp));
	printf("\t'%d'\t'%d'\n", ft_strncmp("", "",             n_strncmp), strncmp("", "",             n_strncmp));
	printf("\t'%d'\t'%d'\n", ft_strncmp("", "",             n_strncmp), strncmp("", "",             n_strncmp));
	printf("\t'%d'\t'%d'\n", ft_strncmp("\200", "\0",       n_strncmp), strncmp("\200", "\0",       n_strncmp));

	printf("\n################################################## MEMCHR ###\n");
	char *tab_memchr = "abcdefghijkl";
	int tab2_memchr[] = {0, 1, 2, 3, 0};

	printf("\n####################### MEMCHR REAL ###\n");

	printf("\n### MINE ###### REAL #############\n");
	printf("\t'%s'\t'%s' \n", (char *)ft_memchr((void *)tab_memchr , 'e', 5),   (char *)memchr((void *)tab_memchr,  'e', 5));
	printf("\t'%s'\t'%s' \n", (char *)ft_memchr((void *)tab_memchr , 'k', 5),   (char *)memchr((void *)tab_memchr,  'k', 5));
	printf("\t'%s'\t'%s' \n", (char *)ft_memchr((void *)tab_memchr , 'k', 100), (char *)memchr((void *)tab_memchr,  'k', 100));
	printf("\t'%s'\t'%s' \n", (char *)ft_memchr((void *)tab_memchr , '_', 100), (char *)memchr((void *)tab_memchr,  '_', 100));
	printf("\t'%s'\t'%s' \n", (char *)ft_memchr((void *)tab_memchr , 'a', 0),   (char *)memchr((void *)tab_memchr,  'a', 0));
	printf("\t'%s'\t'%s' \n", (char *)ft_memchr((void *)""         , 'a', 0),   (char *)memchr((void *)"",          'a', 0));

	// printf("'%s'             '%s' \n", (char *)ft_memchr((void *)tab2_memchr, 'a', -1),  (char *)memchr((void *)tab2_memchr, 'a', -1));
	// printf("'%d'             '%d' \n", (int)ft_memchr((void *)tab2_memchr, 3, 100),   (int)memchr((void *)tab2_memchr, 3, 100));

	printf("\n################################################# MEMCMP ###\n");
	size_t n_memcmp = 200;

	printf("\n### MINE ###### REAL #############\n");
	printf("\t'%d'\t'%d'\n", ft_memcmp("hello", "hello",   n_memcmp), memcmp("hello", "hello",   n_memcmp));
	printf("\t'%d'\t'%d'\n", ft_memcmp("hello", "hello\n", n_memcmp), memcmp("hello", "hello\n", n_memcmp));
	printf("\t'%d'\t'%d'\n", ft_memcmp("hello", "helloa",  n_memcmp), memcmp("hello", "helloa",  n_memcmp));
	printf("\t'%d'\t'%d'\n", ft_memcmp("aab",   "aaa",     n_memcmp), memcmp("aab",   "aaa",     n_memcmp));
	printf("\t'%d'\t'%d'\n", ft_memcmp("aab",   "",        n_memcmp), memcmp("aab",   "",        n_memcmp));
	printf("\t'%d'\t'%d'\n", ft_memcmp("",      "bbb",     n_memcmp), memcmp("",      "bbb",     n_memcmp));
	printf("\t'%d'\t'%d'\n", ft_memcmp("",      "",        n_memcmp), memcmp("",      "",        n_memcmp));
	printf("\t'%d'\t'%d'\n", ft_memcmp("",      "",        n_memcmp), memcmp("",      "",        n_memcmp));

	printf("\n################################################# STRNSTR ###\n");
	// size_t len_strnstr = 14;
	size_t len_strnstr = 15;
	// size_t len_strnstr = 0;

	printf("\n### MINE ###### REAL #############\n");
	printf("\t'%s'\t'%s'\n", ft_strnstr("hello",              "hello",     len_strnstr), strnstr("hello",              "hello",     len_strnstr));
	printf("\t'%s'\t'%s'\n", ft_strnstr("hello",              "lo",        len_strnstr), strnstr("hello",              "lo",        len_strnstr));
	printf("\t'%s'\t'%s'\n", ft_strnstr("hello",              "helloa",    len_strnstr), strnstr("hello",              "helloa",    len_strnstr));
	printf("\t'%s'\t'%s'\n", ft_strnstr("hellohello",         "hello",     len_strnstr), strnstr("hellohello",         "hello",     len_strnstr));
	printf("\t'%s'\t'%s'\n", ft_strnstr("hellohello",         "lo",        len_strnstr), strnstr("hellohello",         "lo",        len_strnstr));
	printf("\t'%s'\t'%s'\n", ft_strnstr("hellohello",         "",          len_strnstr), strnstr("hellohello",         "",          len_strnstr));
	printf("\t'%s'\t'%s'\n", ft_strnstr("",                   "",          len_strnstr), strnstr("",                   "",          len_strnstr));
	printf("\t'%s'\t'%s'\n", ft_strnstr("",                   "aa",        len_strnstr), strnstr("",                   "aa",        len_strnstr));
	printf("\t'%s'\t'%s'\n", ft_strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", len_strnstr), strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", len_strnstr));

	printf("\n#################################################### ATOI ###\n");
	printf("\n### MINE ###### REAL #############\n");
	printf("\t'%d'\t'%d'\n", ft_atoi("hello"),           atoi("hello"));
	printf("\t'%d'\t'%d'\n", ft_atoi("0"),               atoi("0"));
	printf("\t'%d'\t'%d'\n", ft_atoi("1"),               atoi("1"));
	printf("\t'%d'\t'%d'\n", ft_atoi("-1"),              atoi("-1"));
	printf("\t'%d'\t'%d'\n", ft_atoi("--1"),             atoi("--1"));
	printf("\t'%d'\t'%d'\n", ft_atoi("+1"),              atoi("+1"));
	printf("\t'%d'\t'%d'\n", ft_atoi("+-1"),             atoi("+-1"));
	printf("\t'%d'\t'%d'\n", ft_atoi("123"),             atoi("123"));
	printf("\t'%d'\t'%d'\n", ft_atoi("-123"),            atoi("-123"));
	printf("\t'%d'\t'%d'\n", ft_atoi("-123a33aaa"),      atoi("-123a33aaa"));
	printf("\t'%d'\t'%d'\n", ft_atoi("a-123"),           atoi("a-123"));
	printf("\t'%d'\t'%d'\n", ft_atoi("    -123"),        atoi("    -123"));
	printf("\t'%d'\t'%d'\n", ft_atoi("  \t\n  -123"),    atoi("  \t\n  -123"));
	printf("\t'%d'\t'%d'\n", ft_atoi("  \t\n  - 123"),   atoi("  \t\n  - 123"));
	printf("\t'%d'\t'%d'\n", ft_atoi("2147483647"),      atoi("2147483647"));
	printf("\t'%d'\t'%d'\n", ft_atoi("214748364800000"), atoi("214748364800000"));
	printf("\t'%d'\t'%d'\n", ft_atoi("-2147483648"),     atoi("-2147483648"));
	printf("\t'%d'\t'%d'\n", ft_atoi("-2147483649"),     atoi("-2147483649"));

	printf("\n################################################## CALLOC ###\n");
	size_t len_calloc = 10;
	size_t nb_elem_calloc = 3;

	// Size max has to return a ptn NULL --
	// size_t len_calloc = SIZE_MAX;
	// size_t nb_elem_calloc = SIZE_MAX;

	int *ptr_calloc = ft_calloc(nb_elem_calloc, len_calloc);
	if (ptr_calloc)
	{
		printf("first: '%c'\n", *ptr_calloc);
		for (size_t i = 0; i < len_calloc; i++)
			printf("'%c' ", (char)ptr_calloc[i]);
	}
	else
		printf("ptr null");
	// printf("\n");
	free(ptr_calloc);

	char *test = ft_calloc(0, 0);
	printf("test: '%c'\n", *test);
	free(test);

	printf("\n####################### CALLOC REAL ###\n");
	int *ptr_calloc_real = calloc(nb_elem_calloc, len_calloc);
	if (ptr_calloc_real)
	{

		printf("first: '%c'\n", *ptr_calloc_real);
		for (size_t i = 0; i < 10; i++)
			printf("'%c' ", (char)ptr_calloc_real[i]);
	}
	else
		printf("ptr null");
	free(ptr_calloc_real);

	printf("\n################################################## STRDUP ###\n");
	printf("\n### MINE ###### REAL #############\n");
	char *res_strdup001 = ft_strdup("abcdefgh");
	char *res_strdup001_real = strdup("abcdefgh");;
	printf("\t'%s'\t'%s'\n", res_strdup001, res_strdup001_real);
	free(res_strdup001);
	free(res_strdup001_real);

	char *res_strdup002 = ft_strdup("b");
	char *res_strdup002_real = strdup("b");;
	printf("\t'%s'\t'%s'\n", res_strdup002, res_strdup002_real);
	free(res_strdup002);
	free(res_strdup002_real);

	char *res_strdup003 = ft_strdup("");
	char *res_strdup003_real = strdup("");;
	printf("\t'%s'\t'%s'\n", res_strdup003, res_strdup003_real);
	free(res_strdup003);
	free(res_strdup003_real);

	// The real one does crash -_-'
	// char *res_strdup004 = ft_strdup(NULL);
	// char *res_strdup004_real = strdup(NULL);;
	// printf("\t'%s'\t'%s'\n", res_strdup004, res_strdup004_real);
	// free(res_strdup004);
	// free(res_strdup004_real);

	printf("\n################################################## SUBSTR ###\n");
	char *sub_substr000 = ft_substr("abcde", 3, 10);
	printf("'de' -> '%s'\n", sub_substr000);
	free(sub_substr000);

	char *sub_substr001 = ft_substr("abcde", 0, 5);
	printf("'abcde'-> '%s'\n", sub_substr001);
	free(sub_substr001);

	char *sub_substr002 = ft_substr("abcde", 8, 10);
	printf("'' -> '%s'\n", sub_substr002);
	free(sub_substr002);

	char *sub_substr003 = ft_substr("", 3, 10);
	printf("'' -> '%s'\n", sub_substr003);
	free(sub_substr003);

	char *sub_substr004 = ft_substr("abcde", 4, 10);
	printf("'e' -> '%s'\n", sub_substr004);
	free(sub_substr004);

	char *sub_substr005 = ft_substr(NULL, 4, 10);
	printf("'NULL' -> '%s'\n", sub_substr005);
	free(sub_substr005);

	printf("\n################################################# STRJOIN ###\n");
	char *dst_strjoin001 = ft_strjoin("hello ", "world");
	printf("-> '%s'\n", dst_strjoin001);
	free(dst_strjoin001);

	char *dst_strjoin002 = ft_strjoin("", "world");
	printf("-> '%s'\n", dst_strjoin002);
	free(dst_strjoin002);

	char *dst_strjoin003 = ft_strjoin("hello", "");
	printf("-> '%s'\n", dst_strjoin003);
	free(dst_strjoin003);

	char *dst_strjoin004 = ft_strjoin("", "");
	printf("-> '%s'\n", dst_strjoin004);
	free(dst_strjoin004);

	printf("\n################################################# STRTRIM ###\n");
	// char *src_strtrim = "";
	// char *src_strtrim = "abchelloabc";
	// char *src_strtrim = "abcabcccc-caaabbbb";
	char *src_strtrim = "abc-hel-abc-lo-abc";
	char *set_strtrim = "abc";
	char *dst_strtrim = ft_strtrim(src_strtrim, set_strtrim);

	printf("'%s'  ->  '%s'", src_strtrim, dst_strtrim);
	free(dst_strtrim);

	printf("\n################################################### SPLIT ###\n");
	printf("--------- 001 -----\n");
	char **dst_split001 = ft_split("Hello to you", ' ');
	char **start_split001 = dst_split001;
	int nb_split001 = 0;
	while (*dst_split001 != NULL)
	{
		printf("'%s'\n", *dst_split001);
		free(*dst_split001);
		dst_split001++;
		nb_split001++;
	}
	printf("-> %d elements\n\n", nb_split001);
	free(start_split001);

	printf("--------- 002 -----\n");
	char **dst_split002 = ft_split("---a---b-c--d-e-f-g-", '-');
	char **start_split002 = dst_split002;
	int nb_split002 = 0;
	while (*dst_split002 != NULL)
	{
		printf("'%s'\n", *dst_split002);
		free(*dst_split002);
		dst_split002++;
		nb_split002++;
	}
	printf("-> %d elements\n\n", nb_split002);
	free(start_split002);

	printf("--------- 003 -----\n");
	char **dst_split003 = ft_split("---a---b-c--d-e-f-g-", '\0');
	char **start_split003 = dst_split003;
	int nb_split003 = 0;
	while (*dst_split003 != NULL)
	{
		printf("'%s'\n", *dst_split003);
		free(*dst_split003);
		dst_split003++;
		nb_split003++;
	}
	printf("-> %d elements\n\n", nb_split003);
	free(start_split003);

	printf("--------- 004 -----\n");
	char **dst_split004 = ft_split("", 'a');
	char **start_split004 = dst_split004;
	int nb_split004 = 0;
	while (*dst_split004 != NULL)
	{
		printf("'%s'\n", *dst_split004);
		free(*dst_split004);
		dst_split004++;
		nb_split004++;
	}
	printf("-> %d elements\n\n", nb_split004);
	free(start_split004);

	printf("--------- 005 -----\n");
	char **dst_split005 = ft_split("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 'a');
	char **start_split005 = dst_split005;
	int nb_split005 = 0;
	while (*dst_split005 != NULL)
	{
		printf("'%s'\n", *dst_split005);
		free(*dst_split005);
		dst_split005++;
		nb_split005++;
	}
	printf("-> %d elements\n\n", nb_split005);
	free(start_split005);
	
	printf("--------- 006 -----\n");
	char **dst_split006 = ft_split("   BLAH   ", ' ');
	char **start_split006 = dst_split006;
	int nb_split006 = 0;
	while (*dst_split006 != NULL)
	{
		printf("'%s'\n", *dst_split006);
		free(*dst_split006);
		dst_split006++;
		nb_split006++;
	}
	printf("-> %d elements\n\n", nb_split006);
	free(start_split006);

	printf("--------- 007 -----\n");
	char **dst_split007 = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
	char **start_split007 = dst_split007;
	int nb_split007 = 0;
	while (*dst_split007 != NULL)
	{
		printf("'%s'\n", *dst_split007);
		free(*dst_split007);
		dst_split007++;
		nb_split007++;
	}
	printf("-> %d elements\n\n", nb_split007);
	free(start_split007);
	

	// printf("\nSplit voluntarily fail ######\n");

	// Add that just after substr:
	// It has to free all strings, the tab and set it to NULL
		// if (strlen(new) == 20)
		// {
		// 	printf("voluntarily fail with: %s\n", new);
		// 	free(new);
		// 	new = NULL;
		// }

	// char **dst_split008 = ft_split("aaa-bbb-12345678901234567890-cccc-dddd", '-');
	// char **start_split008 = dst_split008;
	// int nb_split008 = 0;

	// if (dst_split008 == NULL)
	// {
	// 	printf("split has failed and the tab has been freed\n");
	// }
	// else
	// {
	// 	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	// 	printf("split has failed but the tab hasn't been free !!!!!!!!!!!!!!!!!!!!!!!\n");
	// }

	printf("\n#################################################### ITOA ###\n");

	for (int i = -20000; i < 20000; i += 333)
	{
		if (ft_atoi(ft_itoa(i)) == i)
			printf("%d -> OK\n", i);
		else
			printf("%d -> NOK <--------------------------------------------\n", i);
	}

	printf("min: %d -> %d\n", INT32_MIN, ft_atoi(ft_itoa(INT32_MIN)));
	printf("max: %d -> %d\n", INT32_MAX, ft_atoi(ft_itoa(INT32_MAX)));

	printf("\n################################################# STRMAPI ###\n");
	char *mapped_001 = ft_strmapi("abcdefghijklmnopqrstuvwxyz", &function_strmapi);
	printf("-> '%s'\n", mapped_001);
	free(mapped_001);

	char *mapped_002 = ft_strmapi("aBcDeFgHiJkLmNoPqRsTuVwXyZ", &function_strmapi);
	printf("-> '%s'\n", mapped_002);
	free(mapped_002);

	char *mapped_003 = ft_strmapi("ABCDEFGHIJKLMNOPQRSTUVWXYZ", &function_strmapi);
	printf("-> '%s'\n", mapped_003);
	free(mapped_003);

	char *mapped_004 = ft_strmapi("", &function_strmapi);
	printf("-> '%s'\n", mapped_004);
	free(mapped_004);

	char *mapped_005 = ft_strmapi(NULL, &function_strmapi);
	printf("-> '%s'\n", mapped_005);
	free(mapped_005);

	char *mapped_006 = ft_strmapi("0123", &function_strmapi);
	printf("-> '%s'\n", mapped_006);
	free(mapped_006);

	printf("\n################################################ STRITERI ###\n");
	char src_iteri001[] = "abcdefghijklmnopqrstuvwxyz";
	ft_striteri(src_iteri001, &function_striteri);
	printf("-> '%s'\n", src_iteri001);

	char src_iteri002[] = "aBcDeFgHiJkLmNoPqRsTuVwXyZ";
	ft_striteri(src_iteri002, &function_striteri);
	printf("-> '%s'\n", src_iteri002);
	
	char src_iteri003[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	ft_striteri(src_iteri003, &function_striteri);
	printf("-> '%s'\n", src_iteri003);

	char src_iteri004[] = "";
	ft_striteri(src_iteri004, &function_striteri);
	printf("-> '%s'\n", src_iteri004);

	char src_iteri005[] = "aaaa";
	ft_striteri(NULL, &function_striteri);
	printf("-> '%s'\n", src_iteri005);

	printf("\n########################################### FD_PUTCHAR_FD ###\n");
	for(int i=0; i<10; i++)
		ft_putchar_fd('a' + i, 1);
	printf("\n############################################ FD_PUTSTR_FD ###\n");
	ft_putstr_fd("hello ", 1);
	ft_putstr_fd("world", 1);
	printf("\n########################################### FD_PUTENDL_FD ###\n");
	ft_putendl_fd("hello world", 1);
	ft_putendl_fd("hello world", 1);
	printf("\n############################################ FD_PUTNBR_FD ###\n");
	ft_putnbr_fd(123, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-1, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-123, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(INT32_MAX, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(INT32_MIN, 1);
	ft_putchar_fd('\n', 1);

	printf("\n############################################### FT_LSTNEW ###\n");
	t_list *lst_new001 = ft_lstnew((void *)ft_strdup("abcdef"));
	printf("node001 content: %s", (char *)lst_new001->content);
	free(lst_new001->content);
	free(lst_new001);

	printf("\n");
	int lst_new_content002 = 123;
	t_list *lst_new002 = ft_lstnew((void *)&lst_new_content002);
	printf("node002 content: %d", *(int *)lst_new002->content);
	free(lst_new002);

	printf("\n######################################### FT_LSTADD_FRONT ###\n");
	t_list *lst_add_001 = ft_lstnew((void *)ft_strdup("mnop"));
	ft_lstadd_front(&lst_add_001, ft_lstnew((void *)ft_strdup("ijkl")));
	ft_lstadd_front(&lst_add_001, ft_lstnew((void *)ft_strdup("efgh")));
	ft_lstadd_front(&lst_add_001, ft_lstnew((void *)ft_strdup("abcd")));

	while (lst_add_001 != NULL)
	{
		printf("%s\n", (char *)lst_add_001->content);
		t_list *to_free = lst_add_001;
		lst_add_001 = lst_add_001->next;
		free(to_free);
	}
	free(lst_add_001);

	printf("######\n");
	t_list *lst_add_002 = ft_lstnew(ft_strdup("start"));
	ft_lstadd_front(&lst_add_002, ft_lstnew((void *)ft_strdup("pouet")));
	while (lst_add_002 != NULL)
	{
		printf("%s\n", (char *)lst_add_002->content);
		t_list *to_free = lst_add_002;
		lst_add_002 = lst_add_002->next;
		free(to_free);
	}
	free(lst_add_002);

	printf("\n############################################## FT_LSTSIZE ###\n");
	t_list *lst_size_001 = ft_lstnew((void *)ft_strdup("1"));
	ft_lstadd_front(&lst_size_001, ft_lstnew((void *)ft_strdup("2")));
	ft_lstadd_front(&lst_size_001, ft_lstnew((void *)ft_strdup("3")));
	ft_lstadd_front(&lst_size_001, ft_lstnew((void *)ft_strdup("4")));
	ft_lstadd_front(&lst_size_001, ft_lstnew((void *)ft_strdup("5")));
	printf("5 -> %d\n", ft_lstsize(lst_size_001));
	while (lst_size_001 != NULL)
	{
		free(lst_size_001->content);
		t_list *to_free = lst_size_001;
		lst_size_001 = lst_size_001->next;
		free(to_free);
	}
	free(lst_size_001);

	printf("###### size of one\n");
	t_list *lst_size_002 = ft_lstnew((void *)ft_strdup("1"));
	printf("1 -> %d\n", ft_lstsize(lst_size_002));
	free(lst_size_002->content);
	free(lst_size_002);

	printf("###### size of zero\n");
	t_list *lst_size_003 = NULL;
	printf("0 -> %d\n", ft_lstsize(lst_size_003));

	printf("\n############################################## FT_LSTLAST ###\n");
	t_list *lst_last_001 = ft_lstnew((void *)ft_strdup("last"));
	ft_lstadd_front(&lst_last_001, ft_lstnew((void *)ft_strdup("2")));
	ft_lstadd_front(&lst_last_001, ft_lstnew((void *)ft_strdup("3")));
	ft_lstadd_front(&lst_last_001, ft_lstnew((void *)ft_strdup("4")));
	ft_lstadd_front(&lst_last_001, ft_lstnew((void *)ft_strdup("5")));

	printf("Last one -> %s\n", (char *)ft_lstlast(lst_last_001)->content);
	while (lst_last_001 != NULL)
	{
		free(lst_last_001->content);
		t_list *to_free = lst_last_001;
		lst_last_001 = lst_last_001->next;
		free(to_free);
	}
	free(lst_last_001);

	printf("######\n");
	t_list *lstlast_002 = NULL;
	if (ft_lstlast(lstlast_002) == NULL)
		printf("last is null (that's ok)\n");
	else
		printf("last is NOT null !!!!!!!! -> FAIL\n");

	printf("######\n");
	t_list *lst_last_003 = ft_lstnew(ft_strdup("only one"));
	printf("Last one -> %s\n", (char *)ft_lstlast(lst_last_003)->content);
	free(lst_last_003->content);
	free(lst_last_003);

	printf("\n########################################### FT_LSTADDLAST ###\n");
	t_list *lst_addback_001 = ft_lstnew((void *)ft_strdup("1"));
	ft_lstadd_back(&lst_addback_001, ft_lstnew((void *)ft_strdup("2")));
	ft_lstadd_back(&lst_addback_001, ft_lstnew((void *)ft_strdup("3")));
	ft_lstadd_back(&lst_addback_001, ft_lstnew((void *)ft_strdup("4")));
	ft_lstadd_back(&lst_addback_001, ft_lstnew((void *)ft_strdup("5")));
	ft_lstadd_back(&lst_addback_001, ft_lstnew((void *)ft_strdup("LAST OK")));

	printf("Last one -> %s\n", (char *)ft_lstlast(lst_addback_001)->content);
	while (lst_addback_001 != NULL)
	{
		free(lst_addback_001->content);
		t_list *to_free = lst_addback_001;
		lst_addback_001 = lst_addback_001->next;
		free(to_free);
	}
	free(lst_addback_001);

	printf("###### Test with empty list\n");
	t_list *lst_addback_002 = NULL;
	printf("size: %d\n", ft_lstsize(lst_addback_002));
	ft_lstadd_back(&lst_addback_002, ft_lstnew((void *)ft_strdup("Only one")));
	printf("Is there one ?\n");
	printf("size: %d -> '%s'\n", ft_lstsize(lst_addback_002), (char *)ft_lstlast(lst_addback_002)->content);
	free(lst_addback_002);

	printf("###### Test with another list added at the end\n");
	int lst_addback_common_content_003 = 42;
	t_list *lst_addback_003_to_add = ft_lstnew((void *)&lst_addback_common_content_003);
	ft_lstadd_back(&lst_addback_003_to_add, ft_lstnew((void *)&lst_addback_common_content_003));
	ft_lstadd_back(&lst_addback_003_to_add, ft_lstnew((void *)&lst_addback_common_content_003));
	ft_lstadd_back(&lst_addback_003_to_add, ft_lstnew((void *)&lst_addback_common_content_003));

	int lst_addback_common_content_start_003 = 33;
	t_list *lst_addback_003_start = ft_lstnew((void *)&lst_addback_common_content_start_003);
	ft_lstadd_back(&lst_addback_003_start, ft_lstnew((void *)&lst_addback_common_content_start_003));

	ft_lstadd_back(&lst_addback_003_start, lst_addback_003_to_add);
	printf("It would be: 33 33 42 42 42 42:\n");
	printf("           : ");
	while (lst_addback_003_start != NULL)
	{
		printf("%d ", *(int*)(lst_addback_003_start->content));
		t_list *to_free = lst_addback_003_start;
		lst_addback_003_start = lst_addback_003_start->next;
		free(to_free);
	}
	free(lst_addback_003_start);
	
	printf("\n############################################ FT_LSTDELONE ###\n");
	t_list *lst_delone_001 = ft_lstnew((void *)ft_strdup("hello"));
	ft_lstdelone(lst_delone_001, function_delone);

	printf("\n############################################# FT_LSTCLEAR ###\n");
	t_list *lst_clear_node_001 = ft_lstnew((void *)ft_strdup("1"));
	t_list *lst_clear_node_002 = ft_lstnew((void *)ft_strdup("2"));
	t_list *lst_clear_node_003 = ft_lstnew((void *)ft_strdup("3"));
	t_list *lst_clear_node_004 = ft_lstnew((void *)ft_strdup("4"));
	t_list *lst_clear_node_005 = ft_lstnew((void *)ft_strdup("5"));

	printf("value of : %s\n", (char *)lst_clear_node_002->content);
	ft_lstadd_back(&lst_clear_node_001, lst_clear_node_002);
	ft_lstadd_back(&lst_clear_node_001, lst_clear_node_003);
	ft_lstadd_back(&lst_clear_node_001, lst_clear_node_004);
	ft_lstadd_back(&lst_clear_node_001, lst_clear_node_005);

	ft_lstclear(&lst_clear_node_001, function_delone);

	if (lst_clear_node_001 == NULL)
		printf("lst clear the list ok\n");
	else
		printf("lst clear the list FAIL !!!!!!!!!!!!!!!!!!!!!!!!\n");

	// printf("###### These nodes have been freed so they have to segfault\n");
	// printf("%s\n", (char *)(lst_clear_node_002->content));
	// printf("%s\n", (char *)(lst_clear_node_003->content));
	// printf("%s\n", (char *)(lst_clear_node_004->content));
	// printf("%s\n", (char *)(lst_clear_node_005->content));

	printf("\n############################################## FT_LSTITER ###\n");
	t_list *lst_lstiter_001 = ft_lstnew((void *)ft_strdup("abcdefghijkl"));
	ft_lstadd_back(&lst_lstiter_001, ft_lstnew((void *)ft_strdup("ABCDEFGHIJKL")));
	ft_lstadd_back(&lst_lstiter_001, ft_lstnew((void *)ft_strdup("abcdefghijkl")));
	ft_lstadd_back(&lst_lstiter_001, ft_lstnew((void *)ft_strdup("ABCDEFGHIJKL")));
	ft_lstadd_back(&lst_lstiter_001, ft_lstnew((void *)ft_strdup("aBcDeFgHiJkL")));
	ft_lstadd_back(&lst_lstiter_001, ft_lstnew((void *)ft_strdup("AbCdEfGhIjKl")));

	printf("###### Before\n");
	t_list *lst_lsiter_001_to_print_before = lst_lstiter_001;
	while (lst_lsiter_001_to_print_before != NULL)
	{
		printf("This node: '%s'\n", (char *)lst_lsiter_001_to_print_before->content);
		lst_lsiter_001_to_print_before = lst_lsiter_001_to_print_before->next;
	}

	ft_lstiter(lst_lstiter_001, &function_lstiter);

	printf("###### After\n");
	t_list *lst_lsiter_001_to_print = lst_lstiter_001;
	while (lst_lsiter_001_to_print != NULL)
	{
		printf("This node: '%s'\n", (char *)lst_lsiter_001_to_print->content);
		lst_lsiter_001_to_print = lst_lsiter_001_to_print->next;
	}

	ft_lstclear(&lst_lstiter_001, &function_delone);

	printf("\n############################################### FT_LSTMAP ###\n");
	t_list *lst_map_001 = ft_lstnew((void *)ft_strdup("0"));
	ft_lstadd_back(&lst_map_001, ft_lstnew((void *)ft_strdup("1")));
	ft_lstadd_back(&lst_map_001, ft_lstnew((void *)ft_strdup("2")));
	ft_lstadd_back(&lst_map_001, ft_lstnew((void *)ft_strdup("3")));
	ft_lstadd_back(&lst_map_001, ft_lstnew((void *)ft_strdup("4")));
	ft_lstadd_back(&lst_map_001, ft_lstnew((void *)ft_strdup("5")));
	ft_lstadd_back(&lst_map_001, ft_lstnew((void *)ft_strdup("6")));
	ft_lstadd_back(&lst_map_001, ft_lstnew((void *)ft_strdup("7")));

	printf("###### LIST SOURCE\n");
	t_list *lst_map_001_start = lst_map_001;
	while (lst_map_001_start != NULL)
	{
		printf("This node: '%s'\n", (char *)lst_map_001_start->content);
		lst_map_001_start = lst_map_001_start->next;
	}

	t_list *lst_map_new_list = ft_lstmap(lst_map_001, &function_lst_map_clone_only_even, function_delone);
	ft_lstclear(&lst_map_001, &function_delone);

	printf("###### LIST DEST\n");
	while (lst_map_new_list != NULL)
	{
		printf("This node: '%s'\n", (char *)lst_map_new_list->content);
		lst_map_new_list = lst_map_new_list->next;
	}
	ft_lstclear(&lst_map_new_list, &function_delone);

	return 0;
}
