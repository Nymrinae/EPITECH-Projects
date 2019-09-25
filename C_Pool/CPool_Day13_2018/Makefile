##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	main.c \
		btree_create_node.c

NAME	=	btree

all: $(NAME)

$(NAME):
	make -C lib/my
	make clean -C lib/my
	gcc -o $(NAME) $(SRC) -Llib/my -lmy

clean:
	rm -f *~

fclean: clean
	rm -f $(NAME)

re:
	fclean all

.PHONY:
	all clean fclean re
