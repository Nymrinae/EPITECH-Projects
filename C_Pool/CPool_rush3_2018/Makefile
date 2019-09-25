##
## EPITECH PROJECT, 2018
## makefile
## File description:
## This file is the makefile of final_stumper project.
##


SRC		=	src/rush3.c \
			src/functions.c \
			src/display.c \
			src/main.c

NAME		=	rush3

CFLAGS		=	-Wall

all:	$(NAME)

$(NAME):
	make -C lib/my
	make clean -C lib/my
	gcc -o $(NAME) $(SRC) $(CFLAGS) -L./lib/my -lmy

clean:
	rm -f *~
	rm -f *.o
	rm -f *#

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
