/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "map.h"
#include "my.h"

void generate_map(char *str, int x, int y, int procedural)
{
	int fd = 0;
	int value = 0;
	char *path = my_strdup("map/");

	srand(seed_map(str));
	path = my_strcat(path, str);
	open(path, O_CREAT, 00666);
	fd = open(path, O_WRONLY);
	write(fd, &x, sizeof(int));
	write(fd, &y, sizeof(int));
	for (int i = 0; i != y; i++)
		for (int j = 0; j != x; j++) {
			value = (rand() % 4 + 4) * procedural;
			write(fd, &value, sizeof(int));
		}
	close(fd);
	free(path);
}

int get_size(map_s *map, int fd)
{
	int error = 0;
	error = read(fd, &map->x, sizeof(int));
	if (error == -1)
		return (84);
	error = read(fd, &map->y, sizeof(int));
	if (error == -1)
		return (84);
	return (0);
}

int read_map(map_s *map, char *path)
{
	int fd = 0;
	int error = 0;

	fd = open(path, O_RDONLY);
	if (fd < 0 || get_size(map, fd) == 84)
		return (84);
	map->map = malloc(sizeof(int *) * map->y);
	for (int y = 0; y != map->y; y++) {
		map->map[y] = malloc(sizeof(int) * map->x);
		for (int x = 0; x != map->x; x++) {
			error = read(fd, &map->map[y][x], sizeof(int));
			if (error == -1) {
				close(fd);
				return (84);
			}
		}
	}
	close(fd);
	return (0);
}

map_s *load_map(char *name)
{
	char *path = my_strdup("map/");
	map_s *map = malloc(sizeof(map_s));
	int error = 0;

	path = my_strcat(path, name);
	error = read_map(map, path);
	free(path);
	if (error == 84) {
		my_putstr("Corrupted map\n");
		free(map);
		return (NULL);
	}
	map->scale_x = 64;
	map->scale_y = 64;
	map->scale_z = 10;
	map->right = 0;
	map->up = 0;
	return (map);
}
