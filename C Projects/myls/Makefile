##
## EPITECH PROJECT, 2018
## makefile
## File description:
## my_ls Mkfl
##

SRC			=	$(wildcard src/*.c) \
				$(wildcard bonus/*.c)

NAME		=	my_ls

LIB_DIR		=	lib/my

CPPFLAGS	+=	-Wall -Wextra -Werror -Iinclude/

LD_FLAGS	=	-L$(LIB_DIR) -lmy

all:	$(NAME)

$(NAME):
	make -C lib/my
	make clean -C lib/my
	gcc -g3 -g -o $(NAME) $(SRC) $(LD_FLAGS)
	make clean

clean:
	rm -f *~
	rm -f *.o
	rm -f *#
	rm -f *.a

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
