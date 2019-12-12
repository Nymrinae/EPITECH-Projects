##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile ftrace
##

NAME 		=	ftrace

SRC			=	$(wildcard src/*.c) \
				$(wildcard src/my_nm/*.c) \
				$(wildcard src/ftrace/*.c) \
				$(wildcard src/strace/*.c) \

CFLAGS		=	-Wall -Wextra -Werror

INCLUDE		= 	-Iinclude/

all:		$(NAME)

$(NAME):
	@gcc $(SRC) $(INCLUDE) -o $(NAME) -g3

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re:	fclean all clean

.PHONY:	all clean fclean re