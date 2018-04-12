/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** selection
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "menu.h"

sfUint32 *get_keyboard(sfUint32 *text, sfEvent event)
{
	sfTime time;
	static int letter = 0;

	time.microseconds = 65000;
	if (event.type == sfEvtTextEntered) {
		if (sfKeyboard_isKeyPressed(sfKeyBack) && letter > 0) {
			letter--;
			text[letter] = '\0';
		} else if (event.text.unicode < 128 &&
			event.text.unicode != 8 && letter < 19) {
			text[letter] = event.text.unicode;
			letter++;
			text[letter] = '\0';
			sfSleep(time);
		}
	}
	return (text);
}

void display_text(sfUint32 *text, sfRenderWindow *window)
{
	sfText *display_text = sfText_create();
	sfVector2f position = {248, 430};
	sfFont *font = sfFont_createFromFile("./ressource/arial.ttf");

	sfText_setUnicodeString(display_text, text);
	sfText_setFont(display_text, font);
	sfText_setColor(display_text, sfBlack);
	sfText_setPosition(display_text, position);
	sfRenderWindow_drawText(window, display_text, NULL);
	sfText_destroy(display_text);
	sfFont_destroy(font);
}

void display_selection(s_sprite **array, sfRenderWindow *window)
{
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, array[2]->sprite, NULL);
	for (int i = 9; i >= 3; i--) {
		sfSprite_setTextureRect(array[i]->sprite, array[i]->rect);
		sfRenderWindow_drawSprite(window, array[i]->sprite, NULL);
	}
	sfSprite_setTextureRect(array[0]->sprite, array[0]->rect);
	sfRenderWindow_drawSprite(window, array[0]->sprite, NULL);
}

void manage_mouse_click_selection(sfVector2i event, s_sprite **array,
	s_map_info *map_info
)
{
	if (event.y >= array[3]->pos.y && event.y <= array[3]->pos.y + 39) {
		if (event.x >= array[3]->pos.x &&
			event.x <= array[3]->pos.x + 148) {
			if (array[3]->rect.left == 0) {
				array[3]->rect.left = 148 * 2;
				map_info->procedural = 1;
			} else {
				array[3]->rect.left = 0;
				map_info->procedural = 0;
			}
		}
		if (event.x >= array[9]->pos.x &&
			event.x <= array[9]->pos.x + 95) {
			if (array[0]->rect.left == 0) {
				map_info->play = 2;
			}
		}
		if (event.x >= array[0]->pos.x &&
			event.x <= array[0]->pos.x + 86) {
			if (array[0]->rect.left == 0) {
				array[0]->rect.left = 86;
				map_info->play = 1;
			}
		}
	}
}

void analyse_events_selection(sfRenderWindow *window, s_sprite **array,
	s_map_info *map_info, sfUint32 *text
)
{
	sfEvent event;
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		else if (sfMouse_isButtonPressed(sfMouseLeft)) {
			manage_mouse_click_selection(mouse_pos, array,
				map_info);
			map_info->size = choose_size(mouse_pos, array,
				map_info->size);
		}
		text = get_keyboard(text, event);
	}
	print_list_map(window);
	display_text(text, window);
	display_number(map_info->size, window);
}

