/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** camera
*/
#include <SFML/Graphics.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

sfVector2f **move_up_down(map_s *map, sfVideoMode mode)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
		map->up++;
		free_map_vector(map);
		map->map2d = create_2d_map(map, mode);
	} else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
		map->up--;
		free_map_vector(map);
		map->map2d = create_2d_map(map, mode);
	}
	return map->map2d;
}

sfVector2f **zoom_dezoom(map_s *map, sfVideoMode mode)
{
	if (sfKeyboard_isKeyPressed(sfKeyPageUp) == sfTrue) {
		map->scale_x += 1;
		map->scale_y += 1;
		free_map_vector(map);
		map->map2d = create_2d_map(map, mode);
	} else if (sfKeyboard_isKeyPressed(sfKeyPageDown) == sfTrue &&
		map->scale_x > 2) {
		map->scale_x -= 1;
		map->scale_y -= 1;
		free_map_vector(map);
		map->map2d = create_2d_map(map, mode);
	} else
		return move_up_down(map, mode);
	return map->map2d;
}

sfVector2f **move(map_s *map, sfVideoMode mode)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
		map->right--;
		free_map_vector(map);
		map->map2d = create_2d_map(map, mode);
	} else if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
		map->right++;
		free_map_vector(map);
		map->map2d = create_2d_map(map, mode);
	} else
		return zoom_dezoom(map, mode);
	return (map->map2d);
}
