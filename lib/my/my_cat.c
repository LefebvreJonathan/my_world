/*
** EPITECH PROJECT, 2017
** cat
** File description:
** Executes the same tasks as your system’s cat command
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./../../include/my.h"
#include <unistd.h>

int my_cat(char *av)
{
	int fd;
	char buffer[31999];
	int size = 0;

	fd = open(av, O_RDONLY);
	if (fd == -1) {
		my_putstr("Error, can read the file.\n");
		return(84);
	}
	size = read(fd, buffer,31999);
	while(size != 0) {
		size = read(fd, buffer, 31999);
		my_putstr(buffer);
	}
	buffer[size] = '\0';
	close(fd);
	return(0);
}
