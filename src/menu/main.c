/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** menu
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "menu.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int destroy_ressources(s_sprite ***array)
{
	for (int i = 14; i >= 0; i--) {
		sfTexture_destroy((*array)[i]->texture);
		sfSprite_destroy((*array)[i]->sprite);
		free((*array)[i]);
	}
	free(*array);
	return 0;
}

int prepare_menu(void)
{
	sfVideoMode mode = {1200, 700, 32};
	sfRenderWindow *window;
	s_sprite **sprite_hud = malloc(sizeof(s_sprite) * 16);

	window = sfRenderWindow_create(mode, "my_world", sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	if (start_ressource(sprite_hud) == 84 ||
		selection_ressource(sprite_hud) == 84)
		return (84);
	if (arrow_ressource(sprite_hud) == 84 ||
		enter_ressource(sprite_hud) == 84)
		return (84);
	menu(sprite_hud, window);
	destroy_ressources(&sprite_hud);
	free(sprite_hud);
	return (0);
}

void check_folder()
{
	struct stat st = {0};

	if (stat("./map", &st) == -1) {
		mkdir("./map", 0700);
}
	    
}
int main(int ac, char **av)
{
	if (ac == 1) {
		check_folder();
		return (prepare_menu());
	} else if (ac == 2 && my_strcmp(av[1], "-h") == 0)
		return (my_cat("./README"));
	else
		return (84);
}
