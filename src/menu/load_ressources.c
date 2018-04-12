/*
** EPITECH PROJECT, 2018
** load_ressource
** File description:
** load the ressources
*/
#include <stdlib.h>
#include "menu.h"

int create_sprite(s_sprite *sprite, char *texture, int *pos)
{
	sfIntRect temp = {pos[0], pos[1], pos[2], pos[3]};
	sfVector2f origin = {pos[4], pos[5]};
	sprite->rect = temp;
	sprite->texture = sfTexture_createFromFile(texture, NULL);
	sprite->sprite = sfSprite_create();

	sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
	sfSprite_setPosition(sprite->sprite, origin);
	if (!sprite->texture || !sprite->sprite)
		return (84);
	sprite->pos = sfSprite_getPosition(sprite->sprite);
	return (0);
}

int snow_dirt_ressource(s_sprite **array)
{
	s_sprite *dirt = malloc(sizeof(s_sprite));
	int pos_dirt[6] = {0, 0, 77, 39, 0, 300};
	int check = create_sprite(dirt, "./ressource/sprite/dirt_button.png",
		pos_dirt);
	s_sprite *snow = malloc(sizeof(s_sprite));
	int pos_snow[6] = {0, 0, 95, 39, 0, 360};
	int check2 = create_sprite(snow, "./ressource/sprite/snow.png",
		pos_snow);
	s_sprite *layer = malloc(sizeof(s_sprite));
	int pos_layer[6] = {0, 0, 100, 500, 0, 180};
	int check3 = create_sprite(layer, "./ressource/sprite/layer.png",
		pos_layer);

	array[10] = layer;
	array[13] = dirt;
	array[14] = snow;
	if (check == 84 || check2 == 84 || check3 == 84)
		return (84);
	return (0);
}

int up_down_ressource(s_sprite **array)
{
	s_sprite *up = malloc(sizeof(s_sprite));
	int pos_up[6] = {0, 0, 67, 39, 0, 180};
	int check = create_sprite(up, "./ressource/sprite/up.png", pos_up);
	s_sprite *down = malloc(sizeof(s_sprite));
	int pos_down[6] = {0, 0, 97, 39, 0, 240};
	int check2 = create_sprite(down, "./ressource/sprite/down.png",
		pos_down);

	array[11] = up;
	array[12] = down;
	if (check == 84 || check2 == 84 || snow_dirt_ressource(array) == 84)
		return (84);
	return (0);
}

int arrow_ressource(s_sprite **array)
{
	s_sprite *up = malloc(sizeof(s_sprite));
	int pos_up[6] = {0, 0, 40, 73, 200, 20};
	int check = create_sprite(up, "./ressource/sprite/arrow_up.png",
		pos_up);
	s_sprite *down = malloc(sizeof(s_sprite));
	int pos_down[6] = {0, 0, 40, 73, 200, 160};
	int check2 = create_sprite(down, "./ressource/sprite/array_down.png",
		pos_down);

	array[6] = up;
	array[7] = down;
	if (check == 84 || check2 == 84 || up_down_ressource(array) == 84)
		return (84);
	return (0);
}

int enter_ressource(s_sprite **array)
{
	s_sprite *procedural = malloc(sizeof(s_sprite));
	int pos_proc[6] = {0, 0, 148, 39, 310, 550};
	int check = create_sprite(procedural,
		"./ressource/sprite/procedural.png", pos_proc);
	s_sprite *reset = malloc(sizeof(s_sprite));
	int pos_reset[6] = {0, 0, 95, 39, 200, 550};
	int check2 = create_sprite(reset, "./ressource/sprite/reset.png",
		pos_reset);
	s_sprite *red = malloc(sizeof(s_sprite));
	int pos_red[6] = {0, 0, 95, 39, 0, 420};
	int check3 = create_sprite(red, "./ressource/sprite/red_reset.png",
		pos_red);

	array[15] = red;
	array[3] = procedural;
	array[9] = reset;
	if (check == 84 || check2 == 84 || check3 == 84)
		return (84);
	return (0);
}

int selection_ressource(s_sprite **array)
{
	s_sprite *enter = malloc(sizeof(s_sprite));
	int pos_enter[6] = {0, 0, 300, 75, 240, 400};
	int check = create_sprite(enter, "./ressource/sprite/enter.png",
		pos_enter);

	s_sprite *list = malloc(sizeof(s_sprite));
	int pos_list[6] = {0, 0, 300, 595, 800, 50};
	int check2 = create_sprite(list, "./ressource/sprite/list.png",
		pos_list);
	s_sprite *x_y = malloc(sizeof(s_sprite));
	int pos_x_y[6] = {0, 0, 398, 49, 15, 100};
	int check3 = create_sprite(x_y, "./ressource/sprite/x_y.png", pos_x_y);

	array[8] = enter;
	array[4] = list;
	array[5] = x_y;
	if (check == 84 || check2 == 84 || check3 == 84)
		return (84);
	return (0);
}

int start_ressource(s_sprite **array)
{
	s_sprite *play = malloc(sizeof(s_sprite));
	s_sprite *quit = malloc(sizeof(s_sprite));
	s_sprite *back = malloc(sizeof(s_sprite));
	int pos_play[6] = {0, 0, 86, 40, 550, 400};
	int pos_quit[6] = {0, 0, 86, 40, 550, 550};
	int pos_back[6] = {0, 0, 1200, 720, 0, 0};
	int check = create_sprite(play, "./ressource/sprite/play_sprite.png",
		pos_play);
	int check2 = create_sprite(quit, "./ressource/sprite/quit_sprite.png",
		pos_quit);
	int check3 = create_sprite(back, "./ressource/sprite/background.png",
		pos_back);

	array[0] = play;
	array[1] = quit;
	array[2] = back;
	if (check == 84 || check2 == 84 || check3 == 84)
		return (84);
	return (0);
}
