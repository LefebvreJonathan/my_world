/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/
#include <SFML/Graphics.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

sfSprite *load_background()
{
	sfSprite *sprite = sfSprite_create();
	sfTexture *texture = NULL;

	texture = sfTexture_createFromFile("ressource/sprite/sky.png", NULL);
	sfSprite_setTexture(sprite, texture, sfTrue);
	return (sprite);
}

int my_world(map_s *map, s_sprite **array, char *name)
{
	int mode_click = 1;
	sfVideoMode mode = {1920, 1080, 32};
	sfRenderWindow *window = sfRenderWindow_create(mode, name,
		sfResize | sfClose, NULL);
	sfEvent event;
	sfSprite *bg = load_background();

	if (!window)
		return (84);
	map->map2d = create_2d_map(map, mode);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
			if (sfMouse_isButtonPressed(sfMouseLeft)) {
				mode_click = click_on_button(array, window,
					mode_click);
				check_reset_button(array, window, map, mode);
			}
		}
		map->map2d = move(map, mode);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, bg, NULL);
		draw_2d_map(window, map, mode_click);
		display_button(array, window);
		check_mouse_on_button(array, window, mode_click);
		event_click(window, map, mode_click);
		sfRenderWindow_display(window);
	}
	free_map_vector(map);
	sfRenderWindow_destroy(window);
	return (0);
}

int init_my_world(s_map_info *info, s_sprite **array)
{
	map_s *map = NULL;

	if (info->new_map == 1)
		generate_map(info->name, info->size, info->size,
			info->procedural);
	map = load_map(info->name);

	if (map == NULL)
		return (84);

	my_world(map, array, info->name);
	save_map(map, info->name);
	free_map_s(map);
	return (0);
}
