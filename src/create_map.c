/*
** EPITECH PROJECT, 2018
** create_map.c
** File description:
** create_map.c
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "convert.h"
#include <stdlib.h>
#include <stdio.h>

sfVector2f project_iso_point(int x, int y, int z, sfVideoMode mode, map_s *map)
{
	sfVector2f point2d = {0, 0};
	float angle_x = degreesToRadians(45);
	float angle_y = degreesToRadians(35);

	point2d.x = cos(angle_x) * x - cos(angle_x) * y;
	point2d.y = sin(angle_y) * y + sin(angle_y) * x - z;
	point2d.x += mode.width / 2 - map->scale_x * 1.5 + map->right * 10;
	point2d.y += mode.height / 3 - map->scale_y * 1.5 + map->up * 10;
	return (point2d);
}

sfVector2f **create_2d_map(map_s *map, sfVideoMode mode)
{
	sfVector2f **map2d = malloc(sizeof(sfVector2f * ) * (map->y));

	for (int i = 0; i != map->y; i++) {
		map2d[i] = malloc(sizeof(sfVector2f) * (map->x));
		for (int j = 0; j != map->x; j++) {
			map2d[i][j] = project_iso_point(j * map->scale_x,
				i * map->scale_y, map->map[i][j] * map->scale_z,
				mode, map);
		}
	}
	return (map2d);
}
