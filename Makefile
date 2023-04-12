##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for *project name*
##

NAME = catshell

SRC	= src/main.c \
	  src/shell/shell_handler.c \
	  src/exec/exec_handler.c \
	  src/exec/getters.c \
	  src/exec/launcher.c \
	  src/commands/command_handler.c \
	  src/commands/getters.c \
	  src/commands/config_command.c \
	  src/commands/builtin/cd_command.c \
	  src/commands/builtin/exit_command.c \
	  src/commands/builtin/env_command.c \
	  src/commands/builtin/setenv_command.c \
	  src/commands/builtin/unsetenv_command.c \
	  src/redirections/redirection_handler.c \
	  src/redirections/getters.c \
	  src/redirections/errors.c \
	  src/redirections/simple_out.c \
	  src/redirections/simple_in.c \
	  src/errors/error_handler.c \
	  src/errors/errors.c \
	  src/errors/utils.c \
	  src/utils/config.c \
	  src/utils/file.c \
	  src/utils/alias.c \
	  src/utils/startup.c \
	  src/utils/free.c \
	  src/utils/getters.c \
	  src/utils/random.c \
	  src/utils/prompt.c

OBJ = $(SRC:.c=.o)
.SILENT:$(OBJ)

CFLAGS = -W -Wall -Wextra -g3

LIBFLAGS = -L./lib -lmy

all: $(NAME)

.SILENT:$(NAME)
$(NAME): $(OBJ)
	@echo "\033[0;32m launching main compilation \033[0m"
	make -C lib
	gcc $(SRC) -o $(NAME) $(CFLAGS) $(LIBFLAGS)
	rm -f $(OBJ)
	@echo "\033[0;32m main compilation done ! \033[0m"

.SILENT:clean
clean:
	@echo "\033[0;32m launching make clean \033[0m"
	make clean -C lib
	rm -f $(OBJ)
	@echo "\033[0;32m make clean compilation done ! \033[0m"

.SILENT:fclean
fclean: clean
	make fclean -C lib
	rm -f $(NAME_LIB)

re: fclean all
	@echo "\033[0;31m make re compilation done ! \033[0m"
