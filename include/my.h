/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include "map.h"
#include <SFML/Graphics.h>
#include "struct.h"

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char int_to_char(int i);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
map_s *load_map(char *name);
void free_map_vector(map_s *map);
void free_map_s(map_s *map);
sfVector2f **create_2d_map(map_s *map, sfVideoMode mode);
void get_point(sfRenderWindow *window, map_s *map, int mode);
int draw_2d_map(sfRenderWindow *window, map_s *map, int mode);
void generate_map(char *str, int x, int y, int procedural);
int my_compute_power_rec(int nb, int p);
char int_to_char(int i);
void save_map(map_s *map, char *name);
char *my_strcpy(char *dest, char const *src);
void free_texture(sfTexture **texture);
void print_edge_right(sfRenderWindow *window, map_s *map, sfTexture **texture);
void print_edge_left(sfRenderWindow *window, map_s *map, sfTexture **texture);
int click_on_button(s_sprite **array, sfRenderWindow *window, int mode);
int check_reset_button(s_sprite **array, sfRenderWindow *window, map_s *map, sfVideoMode mode);
int display_button(s_sprite **array, sfRenderWindow *window);
void animate_button(s_sprite **array, int i, sfVector2i mouse);
int click_on_button(s_sprite **array, sfRenderWindow *window, int mode);
int block_button(s_sprite **array, int i);
int check_reset_button(s_sprite **array, sfRenderWindow *window, map_s *map, sfVideoMode mode);
void event_click(sfRenderWindow *window, map_s *map, int mode_click);
int check_mouse_on_button(s_sprite **array, sfRenderWindow *window, int button_mode);
int seed_map(char *name);
int my_cat(char *str);
sfVector2f **move(map_s *map, sfVideoMode mode);


#endif //MY_H_
