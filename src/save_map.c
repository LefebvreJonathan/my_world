/*
** EPITECH PROJECT, 2017
** save_map.c
** File description:
** save_map function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "map.h"

void save_map(map_s *map, char *name)
{
	char *path = my_strdup("map/");
	int fd = 0;

	path = my_strcat(path, name);
	fd = open(path, O_WRONLY);
	if (fd == -1) {
		free(path);
		my_putstr("Unable to save\n");
		return;
	}
	write(fd, &map->x, sizeof(int));
	write(fd, &map->y, sizeof(int));
	for (int y = 0; y != map->y; y++)
		for (int x = 0; x != map->x; x++) {
			write(fd, &map->map[y][x], sizeof(int));
		}
	close(fd);
}