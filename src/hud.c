/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** hud
*/
#include <SFML/Graphics.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void event_click(sfRenderWindow *window, map_s *map, int mode_click)
{
	if (sfMouse_isButtonPressed(sfMouseLeft))
		get_point(window, map, mode_click);
}

void reset_map(map_s *map, sfVideoMode mode)
{
	for (int y = 0; y != map->y; y++)
		for (int x = 0; x != map->x; x++)
			map->map[y][x] = 0;
	map->map2d = create_2d_map(map, mode);
}

int check_reset_button(s_sprite **array, sfRenderWindow *window, map_s *map,
	sfVideoMode mode
)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

	if (mouse.x >= array[15]->pos.x && mouse.x <= array[15]->pos.x + 95)
		if (mouse.y >= array[15]->pos.y &&
			mouse.y <= array[15]->pos.y + 39)
			reset_map(map, mode);
	return 0;
}

int click_on_button(s_sprite **array, sfRenderWindow *window, int mode)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

	if (mouse.x >= array[11]->pos.x && mouse.x <= array[11]->pos.x + 67 &&
		mouse.y >= array[11]->pos.y)
		if (mouse.y <= array[11]->pos.y + 39)
			return 1;
	if (mouse.x >= array[12]->pos.x && mouse.x <= array[12]->pos.x + 97 &&
		mouse.y >= array[12]->pos.y)
		if (mouse.y <= array[12]->pos.y + 39)
			return 2;
	if (mouse.x >= array[13]->pos.x && mouse.x <= array[13]->pos.x + 77 &&
		mouse.y >= array[13]->pos.y)
		if (mouse.y <= array[13]->pos.y + 39)
			return 3;
	if (mouse.x >= array[14]->pos.x && mouse.x <= array[14]->pos.x + 95 &&
		mouse.y >= array[14]->pos.y)
		if (mouse.y <= array[14]->pos.y + 39)
			return 4;
	return mode;
}

int check_mouse_on_button(s_sprite **array, sfRenderWindow *window,
	int button_mode
)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
	static int old_button_mode = 1;

	if (button_mode == 0)
		button_mode = old_button_mode;
	if (button_mode != old_button_mode)
		array[old_button_mode + 10]->rect.left = 0;
	for (int i = 11; i <= 14; i++)
		if (button_mode + 10 != i)
			animate_button(array, i, mouse_pos);
		else
			block_button(array, i);
	old_button_mode = button_mode;
	return button_mode;
}