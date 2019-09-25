##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	guess_language.c	\
			freq.c			\
			print.c			\
			main.c

OBJ		=	$(SRC:.c=.o)

NAME		=	rush2

ARCHIVE_DIR     =	lib/

LIB_DIR		=	$(ARCHIVE_DIR)/my/

CPPFLAGS	+=	-Wall -Wextra -Werror -Iinclude/

LDFLAGS		=	-L$(ARCHIVE_DIR) -lmy

all:		$(NAME)

build_lib:
	cd $(LIB_DIR) && make

$(NAME):	build_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	cd $(LIB_DIR) && make clean

fclean:	clean
	rm -f $(NAME)
	cd $(LIB_DIR) && make fclean

re:	fclean all

.PHONY:	all build_lib clean fclean re
