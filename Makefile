##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile code source
##

SRC = 	src/main.c				\
		src/open_window.c		\
		src/create_shape.c		\
		src/manage_colision.c	\
		src/normals.c			\
		src/vertices.c			\
		src/geo_ope.c			\
		src/projection.c		\
		src/point_in_rec.c		\

NAME = sat_algorithm

OBJ = $(SRC:.c=.o)

LDFLAGS = -lcsfml-graphics -lcsfml-window -lm

CPPFLAGS = -I./include

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re