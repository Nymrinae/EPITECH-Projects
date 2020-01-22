##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for menger
##

SRC		=	main.c \
			menger.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	 -std=gnu11 -Wall -Wextra

NAME	=	menger

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: fclean re all clean
