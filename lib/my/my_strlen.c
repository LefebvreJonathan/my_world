/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** ;
*/
#include "../../include/printf.h"

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i++;
	}
	return (i);
}
