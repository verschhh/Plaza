7=#
## EPITECH PROJECT, 2022
## plazza
## File description:
## Makefile
##

SRC 	=	main.cpp \
			$(shell find ./src/ -name '*.cpp')

OBJ		=	$(SRC:.cpp=.o)

CFLAGS	=	-std=gnu11 -Wall -Wextra -pthread -I include -g3

NAME	=	plazza

all:	$(NAME)

$(NAME): $(OBJ)
	g++ $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re