/*
** EPITECH PROJECT, 2018
** select_map.c
** File description:
** select_map.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "menu.h"

int select_map(s_sprite **array, sfRenderWindow *window)
{
	sfVector2f new_vector = {500, 550};
	sfUint32 *text = malloc(sizeof(sfUint32) * 20);
	s_map_info *map_info = malloc(sizeof(s_map_info));
	map_info->procedural = 0;
	map_info->size = 2;
	map_info->play = 0;

	text[0] = '\0';
	array[0]->rect.left = 0;
	sfSprite_setPosition(array[0]->sprite, new_vector);
	array[0]->pos = sfSprite_getPosition(array[0]->sprite);
	while (sfRenderWindow_isOpen(window) && map_info->play == 0) {
		display_selection(array, window);
		analyse_events_selection(window, array, map_info, text);
	}
	if (map_info->play != 0) {
		map_info->name = convert_to_str(text);
		map_info->new_map = check_new_map(map_info->name,
			map_info->play);
		init_my_world(map_info, array);
		sfRenderWindow_close(window);
		sfRenderWindow_destroy(window);
	}
	free(text);
	return (0);
}
