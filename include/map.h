/*
** EPITECH PROJECT, 2018
** map.h
** File description:
** map.h
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics.h>

typedef struct map {
	int **map;
	sfVector2f **map2d;
	int x;
	int y;
	int scale_x;
	int scale_y;
	int scale_z;
	int up;
	int right;
} map_s;

#endif //MAP_H
