/*
** EPITECH PROJECT, 2018
** menu
** File description:
** function to manage what data the user will fill
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "menu.h"

int choose_size(sfVector2i mouse, s_sprite **array, int size)
{
	if (mouse.x >= array[6]->pos.x && mouse.x <= array[6]->pos.x + 40) {
		if (mouse.y >= array[6]->pos.y &&
			mouse.y <= array[6]->pos.y + 73) {
			size++;
		} else if (mouse.y >= array[7]->pos.y &&
			mouse.y <= array[7]->pos.y + 73) {
			size--;
		}
	}
	if (size < 2)
		size = 2;
	return (size);
}

void display_number(int size, sfRenderWindow *window)
{
	sfText *text_x = sfText_create();
	sfText *text_y = sfText_create();
	sfVector2f position_x = {100, 100};
	sfVector2f position_y = {260, 100};
	sfFont *font = sfFont_createFromFile("./ressource/arial.ttf");

	sfText_setString(text_x, int_to_string(size));
	sfText_setFont(text_x, font);
	sfText_setPosition(text_x, position_x);
	sfText_setColor(text_x, sfBlack);
	sfText_setString(text_y, int_to_string(size));
	sfText_setFont(text_y, font);
	sfText_setPosition(text_y, position_y);
	sfText_setColor(text_y, sfBlack);
	sfRenderWindow_drawText(window, text_x, NULL);
	sfRenderWindow_drawText(window, text_y, NULL);
	sfRenderWindow_display(window);
}