/*
** EPITECH PROJECT, 2018
** header
** File description:
** header
*/

#ifndef MENU_H_
#define MENU_H_

#include "struct.h"


int my_compute_power_rec(int nb, int p);

char int_to_char(int i);

int start_ressource(s_sprite **array);

int selection_ressource(s_sprite **array);

int enter_ressource(s_sprite **array);

int arrow_ressource(s_sprite **array);

char *set_list(char *path);

char *my_strcat(char *dest, char const *src);

char *my_strdup(char const *src);

int my_strlen(char const *str);

char **str_to_array_line(char const *str);

int my_strcmp(char const *s1, char const *s2);

char *int_to_string(int nb);

int select_map(s_sprite **array, sfRenderWindow *window);

int choose_size(sfVector2i mouse, s_sprite **array, int size);

int init_my_world(s_map_info *info,s_sprite **array);

void display_number(int size, sfRenderWindow *window);

void menu(s_sprite **array, sfRenderWindow *window);

int check_new_map(char *text, int play);

char *convert_to_str(sfUint32 *text);

void print_list_map(sfRenderWindow *window);

int select_map(s_sprite **array, sfRenderWindow *window);

void display_selection(s_sprite **array, sfRenderWindow *window);

void analyse_events_selection(sfRenderWindow *window, s_sprite **array,
	s_map_info *map_info, sfUint32 *text);


#endif //MENU_H_