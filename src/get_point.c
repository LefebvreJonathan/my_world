/*
** EPITECH PROJECT, 2018
** get_point.c
** File description:
** get_point.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "map.h"

void set_circle(sfVector2f pos, sfVector2f origin, float radius,
	sfRenderWindow *window
)
{
	sfCircleShape *circle = sfCircleShape_create();

	sfCircleShape_setRadius(circle, radius);
	sfCircleShape_setOrigin(circle, origin);
	sfCircleShape_setPosition(circle, pos);
	sfCircleShape_setOutlineThickness(circle, 4);
	sfCircleShape_setFillColor(circle, sfTransparent);
	sfCircleShape_setOutlineColor(circle, sfRed);
	sfRenderWindow_drawCircleShape(window, circle, NULL);
	sfCircleShape_destroy(circle);
}

void modify_point(map_s *map, int mode, int point[2])
{
	if (mode == 1) {
		map->map[point[0]][point[1]] += 1;
		map->map2d[point[0]][point[1]].y -= 10;
	} else if (mode == 2) {
		map->map[point[0]][point[1]] -= 1;
		map->map2d[point[0]][point[1]].y += 10;
	}
}

void get_point(sfRenderWindow *window, map_s *map, int mode)
{
	static int type = 1;
	sfVector2i position = sfMouse_getPositionRenderWindow(window);
	sfVector2f origin = {10, 10};
	int point[2] = {0, 0};

	if (mode == 1 || mode == 2)
		type = mode;
	for (int i = 0; i != map->y; i++)
		for (int j = 0; j != map->x; j++)
			if ((map->map2d[i][j].x <= position.x + 15 &&
				map->map2d[i][j].x >= position.x - 15) &&
				(map->map2d[i][j].y <= position.y + 15 &&
					map->map2d[i][j].y >=
						position.y - 15)) {
				set_circle(map->map2d[i][j], origin, 10.0,
					window);
				point[0] = i;
				point[1] = j;
				modify_point(map, type, point);
			}
}
