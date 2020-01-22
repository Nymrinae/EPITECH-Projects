##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make libstring
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	= libstring.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:
		all clean fclean re