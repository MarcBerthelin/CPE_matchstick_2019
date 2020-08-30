##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## t1
##

SRC		=	main.c	\
			make_board.c	\
			play.c	\
			game.c	\
			ai_behaviour.c	\
			check_match.c	\

OBJ		=	$(SRC.c=.o)

LIB	=	-L lib/my/ -l my

CFLAGS  =	-W -Wall -I./include/

VAL	=	--leak-check=full --track-origins=yes

NAME    =   matchstick

all:	$(NAME)

$(NAME):
	make -C lib/my/
	gcc -o $(NAME) $(CFLAGS) $(SRC) $(LIB) -lm

clean:
	rm -f $(OBJ)
	make -C ./lib/my clean

fclean: clean
	rm -rf $(NAME)

re:	fclean all

valgrind:
	make -C lib/my/
	gcc -g -o $(NAME) $(CFLAGS) $(SRC) $(LIB) -lm
	valgrind $(VAL) ./matchstick 3 5
	rm -f vgcore.*
