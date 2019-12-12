##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for minishell2
##

SRC	=	$(wildcard src/*.c) \
		$(wildcard src/errors/*.c) \
		$(wildcard src/functions/*.c) \
		$(wildcard src/functions/cd/*.c) \
		$(wildcard src/functions/path/*.c) \
		$(wildcard src/functions/setenv/*.c) \
		$(wildcard src/shell/*.c) \
		$(wildcard src/parsing/*.c) \
		$(wildcard src/redirection/*.c)

LIB	=	-L lib/my -lmy

INC	=	-I include -I lib/my/include

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	$(INC)

NAME	=	mysh

all:	$(NAME)	clean

$(NAME):
	cd lib/my && make
	gcc -o $(NAME) $(SRC) -g3 $(LIB) $(CFLAGS) $(INC)

clean:
	rm -f *~ *.gcda *.gcno

fclean:
	rm -f $(NAME)

re:	fclean all
