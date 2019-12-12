##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	=	myftp

SRC		=	${wildcard src/*.c} \
			${wildcard src/cmds/*.c}

INCLUDE = 	-Iinclude/

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME) ${CLI_BIN}

$(NAME):
	@gcc -o $(NAME) $(SRC) ${SRC_SRV} $(INCLUDE) -g3

clean:
	@rm -f *.o

fclean:	clean
	@rm -f $(NAME)

re:	fclean all clean

.PHONY:	all clean fclean re
