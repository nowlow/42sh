##
## EPITECH PROJECT, 2019
## PSU_42sh_2018
## File description:
## Makefile
##

SRC					=					src/commands_parser.c					\
										src/main.c								\
										src/multi_commands.c					\
										src/run.c								\
										src/shell.c								\
										src/aliases/add_alias.c					\
										src/aliases/alias_handle.c				\
										src/aliases/get_alias.c					\
										src/commands/change_dir.c				\
										src/commands/exec_from_path.c			\
										src/commands/execmd.c					\
										src/commands/get_out.c					\
										src/commands/print_env.c				\
										src/commands/set_env.c					\
										src/commands/unset_env.c				\
										src/dividers/exec_it.c					\
										src/dividers/redirect_it.c				\
										src/dividers/repartition.c				\
										src/globals/globals.c					\
										src/utils/env_actions.c					\
										src/utils/env.c							\
										src/utils/errors.c						\
										src/utils/linked_list.c					\
										src/utils/paths.c						\
										src/utils/pwd.c							\
										src/utils/string/count_cols.c			\
										src/utils/string/double_array.c			\
										src/utils/string/get_next_line.c		\
										src/utils/string/merge.c				\
										src/utils/string/my_getnbr.c			\
										src/utils/string/my_strdup.c			\
										src/utils/string/size.c					\
										src/utils/string/string.c				\
										src/prompt/display.c					\
										src/prompt/key.c						\
										src/prompt/prompt.c						\
										src/prompt/str_key_edit.c				\
										src/prompt/strings.c					\
										src/prompt/termios.c					\
										src/prompt/cursor/arrows.c				\
										src/prompt/cursor/commands.c			\

OBJ					=					$(SRC:.c=.o)

NAME				=					42sh

CFLAGS				=					-Iinclude -g3 #-Wall -Wextra

LIBS				=					-lncurses

CC					=					gcc

all :				$(NAME)

$(NAME) :			$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean :
	rm -f $(OBJ)

fclean :			clean
	rm -f $(NAME)

re :				fclean all

mouli :
	@./tests/mouli ./ --clean

.PHONY :			all $(NAME) clean fclean all