##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for Ex0
##

SRC		=	${wildcard *.cpp}

CPPFLAGS	=	-Wall -Wextra -Werror

NAME	=	my_convert_temp

all:	$(NAME)

$(NAME):
	g++ -o $(NAME) $(SRC) $(CPPFLAGS)

clean:
	rm -f *~
	rm -f *.o
	rm -f *#

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: fclean re all clean
