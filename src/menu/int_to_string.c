/*
** EPITECH PROJECT, 2017
** int to string
** File description:
** convert int into string
*/
#include <stdlib.h>
#include "menu.h"

char *int_to_string(int nb)
{
	int i = 0;
	char *result;
	int power = 0;

	while (nb % my_compute_power_rec(10, power) != nb)
		power++;
	result = malloc(sizeof(char) * (power + 1));
	for (i = power; i >= 0; i--) {
		result[i] = int_to_char(nb % 10);
		nb = nb / 10;
	}
	result[power + 1] = '\0';
	return (result);
}
