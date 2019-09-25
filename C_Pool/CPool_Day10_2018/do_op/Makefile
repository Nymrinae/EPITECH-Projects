##
## EPITECH PROJECT, 2018
## do-op
## File description:
## Makefile do-op
##

SRC	=	do_op.c

NAME	=	do-op

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -L./../lib/my -lmy

clean:
	rm -f *~

fclean:
	rm -f $(NAME)

re:
	fclean all

.PHONY:	all clean fclean re 
