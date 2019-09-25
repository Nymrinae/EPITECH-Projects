##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## cat 
##

SRC	=	main.c \
		fct.c

NAME	=	cat

all:
	make -C ../lib/my/
	make clean -C ../lib/my/
	gcc $(SRC) -o $(NAME) -L../lib/my -lmy

clean:
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:
	fclean all

.PHONY:
	all re clean fclean
