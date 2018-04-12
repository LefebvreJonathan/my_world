/*
** EPITECH PROJECT, 2018
** print_edge
** File description:
** print_edge
*/

#include "map.h"
#include <math.h>

void print_edge_left(sfRenderWindow *window, map_s *map, sfTexture **texture)
{
	sfConvexShape *convex = sfConvexShape_create();
	sfVector2f begin = map->map2d[0][map->x - 1];
	sfVector2f end = map->map2d[map->y - 1][map->x - 1];
	int size = pow(pow((begin.x - end.x), 2) * 2, 0.5) / 4;

	begin.y += size;
	end.y += size;
	sfConvexShape_setTexture(convex, texture[1], sfTrue);
	sfConvexShape_setOutlineColor(convex, sfWhite);
	sfConvexShape_setOutlineThickness(convex, 1.5);
	sfConvexShape_setPointCount(convex, map->y + 2);
	for (int n = 0; n != map->x; n++)
		sfConvexShape_setPoint(convex, n, map->map2d[n][map->x - 1]);
	sfConvexShape_setPoint(convex, map->y, end);
	sfConvexShape_setPoint(convex, map->y + 1, begin);
	sfConvexShape_setFillColor(convex, sfBlue);
	sfRenderWindow_drawConvexShape(window, convex, NULL);
	sfConvexShape_destroy(convex);
}

void print_edge_right(sfRenderWindow *window, map_s *map, sfTexture **texture)
{
	sfConvexShape *convex = sfConvexShape_create();
	sfVector2f begin = map->map2d[map->y - 1][0];
	sfVector2f end = map->map2d[map->y - 1][map->x - 1];
	sfVector2i params = {map->y - 1, 0};
	int size = pow(pow((begin.x - end.x), 2) * 2, 0.5) / 4;

	begin.y += size;
	end.y += size;
	sfConvexShape_setTexture(convex, texture[1], sfTrue);
	sfConvexShape_setOutlineColor(convex, sfWhite);
	sfConvexShape_setOutlineThickness(convex, 1.5);
	sfConvexShape_setPointCount(convex, map->y + 2);
	for (params.y = 0; params.y != map->x; params.y++)
		sfConvexShape_setPoint(convex, params.y,
			map->map2d[params.x][params.y]);
	sfConvexShape_setPoint(convex, map->y, end);
	sfConvexShape_setPoint(convex, map->y + 1, begin);
	sfConvexShape_setFillColor(convex, sfBlue);
	sfRenderWindow_drawConvexShape(window, convex, NULL);
	sfConvexShape_destroy(convex);
}
