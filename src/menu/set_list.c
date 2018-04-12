/*
** EPITECH PROJECT, 2018
** set_list.c
** File description:
** set_list.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include "menu.h"
#include <unistd.h>

char *set_list(char *path)
{
	DIR *directory = NULL;
	char *list = my_strdup("");
	struct dirent *test;

	directory = opendir(path);
	if (directory == NULL)
		return (NULL);
	test = readdir(directory);
	while (test != NULL) {
		if (test->d_name[0] != '.') {
			list = my_strcat(list, test->d_name);
			list = my_strcat(list, "\n");
		}
		test = readdir(directory);
	}
	closedir(directory);
	return (list);
}
