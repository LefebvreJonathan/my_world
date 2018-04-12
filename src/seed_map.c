/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by LEFEBVRE Jonathan
*/


int seed_map(char *name)
{
	int seed = 0;

	for (int i = 0; name[i] != 0; i++)
		seed += name[i];
	return (seed);
}