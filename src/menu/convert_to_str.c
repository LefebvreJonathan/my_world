/*
** EPITECH PROJECT, 2018
** convert_to_str.c
** File description:
** convert_to_str.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "menu.h"

char *convert_to_str(sfUint32 *text)
{
	int size = 0;
	char *str = NULL;

	if (text[0] == '\0') {
		str = my_strdup("my_world");
		return (str);
	}
	while (text[size] != 0)
		size++;
	str = malloc(sizeof(char) * size + 1);
	for (int n = 0; text[n] != 0; n++)
		str[n] = text[n];
	str[size] = 0;
	return (str);
}
