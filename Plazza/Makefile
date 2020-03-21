##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CXX		=       g++

RM		=	rm -f

INCDIRS		=	$(addprefix -I, $(shell find ./include -type d -print))

CXXFLAGS	=       -Wall -Wextra
CXXFLAGS	+=      $(INCDIRS)
THREADFLAGS	=	-lpthread -lrt

NAME		=	plazza

SRCS		=	$(wildcard src/*.cpp) \
			$(wildcard src/IPC/*.cpp) \
			$(wildcard src/Kitchen/*.cpp) \
			$(wildcard src/Parsing/*.cpp) \
			$(wildcard src/Reception/*.cpp)

OBJS            =       $(addsuffix .o, $(basename $(SRCS)))

all             :       $(NAME)

$(NAME)         :       $(OBJS)
		@$(CXX) -o $(NAME) $(OBJS) $(THREADFLAGS)
		@printf "[\033[1;33mBuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.'
		@echo -e "\033[34m\n==== \033[35mCOMPLETED\033[34m ====\033[0m"

clean           :
		@$(RM) $(OBJS)
		@printf "[\033[1;31mDeleted_Obj\033[0m] % 30s\n" $(OBJS) | tr ' ' '.'

fclean          :       clean
		@$(RM) $(NAME)
		@printf "[\033[1;31mDeleted_Binary\033[0m] % 30s\n" $(NAME) | tr ' ' '.'

re              :       fclean all

%.o		:	%.cpp
		@$(CXX) $(CXXFLAGS) -c -o $@ $<
		@echo -e "[\e[32mCompiled\033[0m]" "---->" $< || echo -e "REALLY NIGGA ??!!" $<

.PHONY		:	all clean fclean re %.o
