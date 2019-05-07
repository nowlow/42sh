##
## EPITECH PROJECT, 2019
## minishell1
## File description:
## makefile
##

NAME	=	mysh

CC		=	gcc

RM		=	rm -f

SRCS	=	./src/main.c					\
			./src/cd.c						\
			./src/env.c						\
			./src/setenv.c					\
			./src/execve.c					\
			./src/unsetenv.c				\
			./src/check_str.c				\
			./src/my_exit.c					\
			./src/my_strcat.c				\
			./src/my_putchar.c				\
			./src/my_strcmp.c				\
			./src/my_strncmp.c				\
			./src/my_strlen.c				\
			./src/my_strdup.c				\
			./src/copy_env.c				\
			./src/my_putstr.c				\
			./src/monitoring.c				\
			./src/parsing_env.c				\
			./src/my_str_to_word_array.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I ./include/
CFLAGS	+=	-W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
