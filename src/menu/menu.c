/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** menu
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "menu.h"

void display(s_sprite **array, sfRenderWindow *window)
{

	sfRenderWindow_clear(window, sfBlack);
	for (int i = 2; i >= 0; i--) {
		sfSprite_setTextureRect(array[i]->sprite, array[i]->rect);
		sfRenderWindow_drawSprite(window, array[i]->sprite, NULL);
	}
	sfRenderWindow_display(window);
}

int manage_mouse_click_menu(sfMouseButtonEvent event, s_sprite **array)
{
	if (event.x >= array[0]->pos.x && event.x <= array[0]->pos.x + 90) {
		if (event.y >= array[0]->pos.y &&
			event.y <= array[0]->pos.y + 40)
			return 1;
		if (event.y >= array[1]->pos.y &&
			event.y <= array[1]->pos.y + 40)
			return 2;
	}
	return (0);
}

void animate_button_menu(sfVector2i mouse, s_sprite **array)
{
	if (mouse.x >= array[0]->pos.x && mouse.x <= array[0]->pos.x + 90) {
		if (mouse.y >= array[0]->pos.y &&
			mouse.y <= array[0]->pos.y + 40) {
			array[0]->rect.left = 86;
		} else
			array[0]->rect.left = 0;
		if (mouse.y >= array[1]->pos.y &&
			mouse.y <= array[1]->pos.y + 40) {
			array[1]->rect.left = 86;
		} else
			array[1]->rect.left = 0;
	} else {
		array[0]->rect.left = 0;
		array[1]->rect.left = 0;
	}
}

int analyse_events_menu(sfRenderWindow *window, s_sprite **array)
{
	sfEvent event;
	sfVector2i position = sfMouse_getPositionRenderWindow(window);
	sfMouseButtonEvent mouse = {sfEvtMouseButtonPressed, sfMouseLeft,
		position.x, position.y};
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		else if (sfMouse_isButtonPressed(sfMouseLeft)) {
			return manage_mouse_click_menu(mouse, array);
		}
	}
	animate_button_menu(mouse_pos, array);
	return 0;
}

void menu(s_sprite **array, sfRenderWindow *window)
{
	int stop = 0;
	while (sfRenderWindow_isOpen(window) && stop == 0) {
		stop = analyse_events_menu(window, array);
		display(array, window);
	}
	if (stop == 2)
		return;
	else
		select_map(array, window);
}