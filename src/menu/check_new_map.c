/*
** EPITECH PROJECT, 2018
** check_new_map.c
** File description:
** check_new_map
*/

#include <stdlib.h>
#include "menu.h"

int check_new_map(char *text, int play)
{
	char *list = set_list("./map");
	char **array = str_to_array_line(list);
	int new_world = 1;
	int i = 0;

	if (play == 2)
		return (1);
	while (array[i] != NULL) {
		if (my_strcmp(array[i], text) == 0)
			new_world = 0;
		i++;
	}
	for (int n = 0; array[n] != NULL; n++)
		free(array[n]);
	free(array);
	free(list);
	return (new_world);
}
