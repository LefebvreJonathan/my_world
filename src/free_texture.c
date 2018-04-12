/*
** EPITECH PROJECT, 2018
** free_texture
** File description:
** free_texture
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

void free_texture(sfTexture **texture)
{
	sfTexture_destroy(texture[0]);
	sfTexture_destroy(texture[1]);
	sfTexture_destroy(texture[2]);
	free(texture);
}
