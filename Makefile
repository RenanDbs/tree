##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	./main.c \
		./my_strcpy.c\
		./my_strlen.c\

INC	=	-I./lib/

NAME	=	tree

all:	$(NAME)

$(NAME):
		gcc $(SRC) $(INC) -o $(NAME) -lm -g3 -Wall -Wextra

clean:
		rm -f $(NAME)

fclean:	clean

re:	fclean	all