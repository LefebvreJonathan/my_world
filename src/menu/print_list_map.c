/*
** EPITECH PROJECT, 2018
** print_list_map.c
** File description:
** print_list_map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "menu.h"

void print_list_map(sfRenderWindow *window)
{
	sfText *text = sfText_create();
	char *list = set_list("./map");
	sfVector2f position = {805, 100};
	sfFont *font = sfFont_createFromFile("./ressource/arial.ttf");

	sfText_setString(text, list);
	sfText_setFont(text, font);
	sfText_setPosition(text, position);
	sfText_setColor(text, sfBlack);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
	sfFont_destroy(font);
	free(list);
}
