##
## EPITECH PROJECT, 2018
## minishell2
## File description:
## Makefile
##

SRC	=	$(wildcard ./src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-I./include -g

CC	=	gcc

all:	$(NAME)

$(NAME):    $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
