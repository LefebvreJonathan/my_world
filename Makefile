##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

NAME	= my_world

CC	= gcc

RM	= rm -f

SRCS	= ./src/create_map.c \
	  ./src/draw_map.c \
	  ./src/free_object.c \
	  ./src/generate_map.c \
	  ./src/get_point.c \
	  ./src/game.c \
	  ./src/menu/data_user.c \
	  ./src/menu/int_to_char.c \
	  ./src/menu/int_to_string.c \
	  ./src/menu/load_ressources.c \
	  ./src/menu/menu.c \
	  ./src/menu/main.c \
      ./src/menu/check_new_map.c \
      ./src/menu/convert_to_str.c \
      ./src/menu/print_list_map.c \
      ./src/menu/select_map.c \
	  ./src/menu/selection.c \
	  ./src/menu/set_list.c \
	  ./src/menu/str_to_array_line.c \
	  ./src/save_map.c \
	  ./src/print_edge.c \
	  ./src/free_texture.c  \
	  ./src/hud.c   \
	  ./src/seed_map.c \
	  ./src/display_button.c    \
	  ./src/camera.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME) clean

$(NAME): $(OBJS)
	 cd lib/my/ && make && make clean
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -L./lib/my/ -lmy -lc_graph_prog -lm

clean:
	$(RM) $(OBJS) ./lib/my/libmy.a

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
