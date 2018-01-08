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

char *paste_strings(char *tab, int size)
{
	int i = 0;
	int j = 0;
	char *tab_global = malloc(size + READ_SIZE);

	while (i < size - 2) {
		tab_global[i] = tab[i];
		i++;
	}
	free(tab);
	tab_global[size + READ_SIZE - 1] = '\0';
	return (tab_global);
}

char *read_mo(int fd, char *buff, int *err, int *size)
{
	free(buff);
	buff = malloc(READ_SIZE + 1);
	if (READ_SIZE >= 0 && buff) {
		*err = read(fd, buff, READ_SIZE);
		if (*err == -1)
			return (NULL);
		*size = *size + READ_SIZE;
		buff[*err] = '\0';
		return (buff);
	} else
		return (NULL);
}

char *good_or_no(int *nb_byte_read, char *tab, int *index_tab)
{
	tab[*index_tab] = '\0';
	if (*nb_byte_read <= 0) {
		free(tab);
		return (NULL);
	}
	return (tab);
}

char *adding_value_on_tab(char *tab, char *buff, int *index_tab, int *where_i_am)
{
	tab[*index_tab] = buff[*where_i_am];
	*index_tab = *index_tab + 1;
	*where_i_am = *where_i_am + 1;
	return (tab);
}

char *get_next_line(int fd)
{
	int index_tab = 0;
	int index_nb_read = 1;
	char *tab = malloc(index_nb_read * READ_SIZE);

	if (nb_byte_read == -2) {
		buff = read_mo(fd, buff, &nb_byte_read, &index_nb_read);
		if (!buff)
			return (NULL);
	}
	while (buff && nb_byte_read != 0 && buff[where_i_am] != '\n') {
		if (where_i_am < nb_byte_read) {
			tab = adding_value_on_tab(tab, buff, &index_tab, &where_i_am);
		} else {
			buff = read_mo(fd, buff, &nb_byte_read, &index_nb_read);
			tab = paste_strings(tab, index_nb_read);
			where_i_am = 0;
		}
	}
	where_i_am++;
	return (good_or_no(&nb_byte_read, tab, &index_tab));
}
