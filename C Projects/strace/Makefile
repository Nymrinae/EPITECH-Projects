##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile strace
##

NAME 		=	strace

SRC			=	$(wildcard src/*.c) \
				$(wildcard src/options/*.c) \
				$(wildcard src/functions/*.c) \
				$(wildcard src/print/*.c)

CFLAGS		=	-Wall -Wextra -Werror

INCLUDE		= 	-Iinclude/

all:		$(NAME)

$(NAME):
	@gcc $(SRC) $(INCLUDE) -o $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re:	fclean all clean

.PHONY:	all clean fclean re