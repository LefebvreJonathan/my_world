/*
** EPITECH PROJECT, 2017
** int to string
** File description:
** convert int into string
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_revstr(char *str)
{
	int n = 0;
	char stock;
	int i = my_strlen(str) - 1;
	int limite = i / 2;

	while (i != limite) {
		stock = str[n];
		str[n] = str[i];
		str[i] = stock;
		n++;
		i--;
	}
	return (str);
}

char *int_to_string(int nbr)
{
	char *number = malloc(sizeof(char) * 9);
	int unit = 0;
	int i = 0;

	while (nbr != 0) {
		unit = nbr % 10;
		nbr = (nbr - unit) / 10;
		number[i] = int_to_char(unit);
		i++;
	}
	number[i] = 0;
	number = my_revstr(number);
	return (number);
}

