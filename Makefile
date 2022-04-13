##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile code source
##

SRC = 	src/main.c								\
		src/open_window.c						\
		src/create_shape.c						\
		src/manage_colision.c					\
		src/normals.c							\
		src/vertices.c							\
		src/geometrical_operations.c			\
		src/projection.c						\
		src/point_in_rec.c						\
		src/init_text.c

NAME = sat_algorithm

OBJ = $(SRC:.c=.o)

LDFLAGS = -lcsfml-graphics -lcsfml-window -lm

CPPFLAGS = -I./include

CFLAGS = -Wall -Wextra

all: built $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)
	rm -f src/*.o

clean:
	rm -f $(OBJ)
	rm -f *#
	rm -f src/*#
	rm -f include/*#
	rm -f *~
	rm -f include/*~
	rm -f src/*~
	rm -f tests/*~
	rm -f lib/my/fonctions/*~
	rm -f *.gcno
	rm -f *.gcda
	rm -f lib/my/libmy.a

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all

built:
	rm -f *.o
