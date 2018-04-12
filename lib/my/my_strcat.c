/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** concatenates two string
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
	int n = 0;
	char *temp = malloc(sizeof(char) * my_strlen(dest) + 1);
	temp = my_strcpy(temp, (dest));
	(dest) = malloc(sizeof(char) * my_strlen(temp) + my_strlen(src) + 1);
	(dest) = my_strcpy((dest), temp);

	while (src[n] != '\0') {
		(dest)[my_strlen(temp) + n] = src[n];
		n++;
	}
	(dest)[my_strlen(temp) + n] = '\0';
	free(temp);
	return dest;
}
