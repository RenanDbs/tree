##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	./main.c \
		./get_active_flags.c	\
		./lib/my_put_nbr.c	\
		./lib/my_putchar.c	\
		./lib/my_putstr.c	\
		./lib/my_revstr.c	\
		./lib/my_strcat.c	\
		./lib/my_strcmp.c	\
		./lib/my_strncat.c	\
		./lib/printer_assistant.c	\
		./lib/printf.c

INC	=	-I./lib/

NAME	=	tree

all:	$(NAME)

$(NAME):
		gcc $(SRC) $(INC) -o $(NAME) -lm -g3 -Wall -Wextra

clean:
		rm -f $(NAME)

fclean:	clean

re:	fclean	all