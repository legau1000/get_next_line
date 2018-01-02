/*
** EPITECH PROJECT, 2018
** get_nextline.c
** File description:
** nextline.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char *paste_strings(char *tab1, char *tab2, int size)
{
	int i = 0;
	int j = 0;
	char *tab_global;

	tab_global = malloc(size * READ_SIZE + 1);
	if (tab1) {
		while (tab1[i]) {
			tab_global[i] = tab1[i];
			i++;
		}
	}
	while (tab2[j]) {
		tab_global[i] = tab2[j];
		j++;
		i++;
	}
	tab_global[i] = '\0';
	return (tab_global);
}

char *read_more(int fd, char *buff, int *err)
{
	free(buff);
	buff = malloc(READ_SIZE + 1);
	if (buff) {
		*err = read(fd, buff, READ_SIZE);
		buff[*err] = '\0';
		return (buff);
	} else
		return (NULL);
}

char *stock_all(char *buff, int fd, int *err)
{
	char *tab1;
	int i = 0;
	int j = 0;
	int y = 0;

	tab1 = malloc(READ_SIZE + 1);
	while (i != *err) {
		tab1[j] = buff[i];
		i++;
		j++;
	}
	tab1[*err] = '\0';
	return (tab1);
}

char *chose_good(char *tab, int *where, int n_tab)
{
	int i = *where;
	int j = i;
	char *tab_return = NULL;

	if (tab && tab[*where]) {
		while (tab[i] != '\0' && tab[i] != '\n')
			i++;
		tab_return = malloc(i - j + 1);
		if (!tab_return)
			return (NULL);
		while (tab[j] && tab[j] != '\n') {
			tab_return[n_tab] = tab[j];
			j++;
			n_tab++;
		}
		*where = *where + n_tab + 1;
		tab_return[n_tab] = '\0';
		return (tab_return);
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	static char *buff;
	int err = 0;
	int where_i_am = 1;

	static int where = 0;
	static char *tab = NULL;
	static char *tab2 = NULL;
	buff = read_more(fd, buff, &err);
	if ((err == 0 && where == 0) || err == -1) {
		return (NULL);
	} else {
		while (err != 0 && where == 0) {
			tab = stock_all(buff, fd, &err);
			tab2 = paste_strings(tab2, tab, where_i_am);
			buff = read_more(fd, buff, &err);
			free(tab);
			where_i_am++;
		}
		return (chose_good(tab2, &where, 0));
	}
}
