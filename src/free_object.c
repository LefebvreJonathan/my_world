/*
** EPITECH PROJECT, 2018
** free_object.c
** File description:
** free_object.c
*/

#include <SFML/Graphics.h>
#include "map.h"
#include <stdlib.h>

void free_map_vector(map_s *map)
{
	for (int i = 0; i != map->y; i++)
		free(map->map2d[i]);
	free(map->map2d);
}

void free_map_s(map_s *map)
{
	for (int i = 0; i != map->y; i++)
		free(map->map[i]);
	free(map->map);
	free(map);
}

