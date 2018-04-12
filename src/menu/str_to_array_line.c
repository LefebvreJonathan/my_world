/*
** EPITECH PROJECT, 2018
** str_to_word_array.c
** File description:
** str to word array
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "menu.h"

int compt_nbr_line(char const *str)
{
	int nbr_word = 0;

	if (str[0] != '\n')
		nbr_word++;
	for (int i = 0; str[i + 1] != 0; i++) {
		if (str[i] == '\n' && str[i + 1] != '\n')
			nbr_word++;
	}
	return (nbr_word);
}

int copy_word_line(char ***array, char const **str, int pos, int word)
{
	int end_word = pos;
	int size_word = 0;

	while ((*str)[end_word] != '\n' && (*str)[end_word] != 0)
		end_word++;
	size_word = end_word - pos;
	(*array)[word] = malloc(sizeof(char) * size_word + 1);
	for (int i = 0; i != size_word; i++)
		(*array)[word][i] = (*str)[i + pos];
	(*array)[word][size_word] = 0;
	return (size_word);
}

char **str_to_array_line(char const *str)
{
	char **array;
	int a = 0;
	int i = 0;

	array = malloc(sizeof(char *) * (compt_nbr_line(str) + 1));
	while (i <= my_strlen(str)) {
		while (str[i] == '\n' && str[i] != 0)
			i++;
		if (str[i] != 0) {
			i += copy_word_line(&array, &str, i, a);
			a++;
		}
		i++;
	}
	array[a] = NULL;
	return (array);
}
