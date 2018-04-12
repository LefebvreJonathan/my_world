/*
** EPITECH PROJECT, 2017
** list.h
** File description:
** manage and create list
*/
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_map_info s_map_info;

struct s_map_info {
	int size;
	int procedural;
	int new_map;
	char *name;
	int play;
};

typedef struct sprite s_sprite;

struct sprite {
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect rect;
	sfVector2f pos;
};

#endif //STRUCT_H