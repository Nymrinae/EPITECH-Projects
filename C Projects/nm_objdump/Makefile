##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile objdump
##

SRCS_NM			=	${wildcard nm/src/*.c}
SRCS_OBJD		=	${wildcard objdump/src/*.c}

NM				=	my_nm
OBJD			=	my_objdump

CFLAGS			=	-Wall -Wextra -Werror

INCLUDE			= 	-Iincludes/

all:				nm objdump

nm:
		@gcc $(SRCS_NM) -o $(NM) $(INCLUDE)

objdump:
		@gcc $(SRCS_OBJD) -o $(OBJD) $(INCLUDE)

clean:
	@rm -f *.o

fclean:	clean
	@rm -f $(NM)
	@rm -f $(OBJD)

re:	fclean all clean

.PHONY:	all clean fclean re nm objdump