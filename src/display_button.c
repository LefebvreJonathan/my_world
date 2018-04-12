/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** display
*/
#include <SFML/Graphics.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int display_button(s_sprite **array, sfRenderWindow *window)
{
	for (int i = 10; i <= 15; i++) {
		sfSprite_setTextureRect(array[i]->sprite, array[i]->rect);
		sfRenderWindow_drawSprite(window, array[i]->sprite, NULL);
	}
	return 0;
}

void animate_button(s_sprite **array, int i, sfVector2i mouse)
{
	int rect = 67;

	if (i == 12)
		rect = 97;
	if (i == 13)
		rect = 77;
	if (i == 14)
		rect = 95;
	if (mouse.x >= array[i]->pos.x && mouse.x <= array[i]->pos.x + rect) {
		if (mouse.y >= array[i]->pos.y &&
			mouse.y <= array[i]->pos.y + 39)
			array[i]->rect.left = rect;
		else
			array[i]->rect.left = 0;
	} else
		array[i]->rect.left = 0;
}

int block_button(s_sprite **array, int i)
{
	int rect = 67;

	if (i == 12)
		rect = 97;
	if (i == 13)
		rect = 77;
	if (i == 14)
		rect = 95;
	array[i]->rect.left = rect * 2;
	return 0;
}
