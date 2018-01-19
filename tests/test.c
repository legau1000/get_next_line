/*
** EPITECH PROJECT, 2017
** Test Criterion
** File description:
** bistro-matic
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "get_next_line.h"

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(Next_line, first_line, .init = redirect_all_std)
{
	char *test = "/*";
	int fd = open("get_next_line.c", O_RDONLY);
	char *line = get_next_line(fd);
	int i = 0;

	while (test[i]) {
		cr_assert(line[i] == test[i]);
		i++;
	}
}

Test(Next_line, Second_line, .init = redirect_all_std)
{
	char *test = "** get_nextline.c";
	int fd = open("get_next_line.c", O_RDONLY);
	char *line = NULL;
	int i = 0;

	get_next_line(fd);
	get_next_line(fd);
	line = get_next_line(fd);
	while (test[i]) {
		cr_assert(line[i] == test[i]);
		i++;
	}
}

Test(Bad_fd, Bad_fd, .init = redirect_all_std)
{
	int fd = open("../test87", O_RDONLY);
	char *line = get_next_line(fd);
	int i = 0;

	cr_assert(line == NULL);
}

Test(Just_n, one_n, .init = redirect_all_std)
{
	int fd = open("tests/bidon", O_RDONLY);
	char *line = get_next_line(fd);
	int i = 0;

	cr_assert(line[0] == '\0');
	line = get_next_line(fd);
	cr_assert(line == NULL);
}
