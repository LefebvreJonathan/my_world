##
## EPITECH PROJECT, 2018
## makefile lib
## File description:
## makefile lib
##

NAME	= libmy.a

RM	= rm -f

SRC	=	./free_array.c \
		./int_to_string.c \
		./int_to_char.c \
		./my_compute_power_rec.c \
		./my_getnbr.c \
		./my_strcat.c \
		./my_strcmp.c \
		./my_strcpy.c \
		./my_strdup.c \
		./my_strlen.c \
		./get_next_line.c \
		./my_putstr.c \
		./my_putchar.c \
		./my_cat.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	 ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
