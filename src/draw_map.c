/*
** EPITECH PROJECT, 2018
** draw_map.c
** File description:
** draw_map.c
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int compt_weight(map_s *map, int i, int j)
{
	int tab[4] = {map->map[i][j], map->map[i][j + 1],
		map->map[i + 1][j + 1], map->map[i + 1][j]};
	int size = 0;

	for (int x = 0; x != 4; x++)
		if (tab[x] >= 5)
			size++;
		else if (tab[x] != 0)
			size--;
	return (size);
}

sfTexture **gen_texture()
{
	sfTexture **texture = malloc(sizeof(sfTexture * ) * 3);

	texture[0] = sfTexture_createFromFile("ressource/sprite/grass.jpg",
		NULL);
	texture[1] = sfTexture_createFromFile("ressource/sprite/dirt.png",
		NULL);
	texture[2] = sfTexture_createFromFile("ressource/sprite/stone.png",
		NULL);
	return (texture);
}

void set_convex_form(sfConvexShape *convex, sfVector2f **map_2d, int i, int j)
{
	sfConvexShape_setPoint(convex, 0, map_2d[i][j]);
	sfConvexShape_setPoint(convex, 1, map_2d[i][j + 1]);
	sfConvexShape_setPoint(convex, 2, map_2d[i + 1][j + 1]);
	sfConvexShape_setPoint(convex, 3, map_2d[i + 1][j]);
}

void set_texture(sfConvexShape *convex, sfTexture **texture, int weight,
	int type
)
{
	if (weight < -3)
		sfConvexShape_setTexture(convex, texture[1], sfTrue);
	else if (weight > 2)
		sfConvexShape_setTexture(convex, texture[2], sfTrue);
	else if (type == 3)
		sfConvexShape_setTexture(convex, texture[1], sfTrue);
	else
		sfConvexShape_setTexture(convex, texture[0], sfTrue);
}

int draw_2d_map(sfRenderWindow *window, map_s *map, int mode)
{
	static int type = 4;
	sfConvexShape *convex = sfConvexShape_create();
	sfTexture **texture = gen_texture();
	int weight = 0;

	if (mode == 3 || mode == 4)
		type = mode;
	sfConvexShape_setPointCount(convex, 4);
	sfConvexShape_setOutlineColor(convex, sfBlack);
	sfConvexShape_setOutlineThickness(convex, 0.8);
	for (int j = 0; j != map->y - 1; j++)
		for (int i = 0; i != map->x - 1; i++) {
			set_convex_form(convex, map->map2d, i, j);
			weight = compt_weight(map, i, j);
			set_texture(convex, texture, weight, type);
			sfRenderWindow_drawConvexShape(window, convex, NULL);
		}
	print_edge_left(window, map, texture);
	print_edge_right(window, map, texture);
	free_texture(texture);
	sfConvexShape_destroy(convex);
	return (0);
}
