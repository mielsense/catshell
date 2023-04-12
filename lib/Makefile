##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makfile for the lib
##

SRC = my/my_strlen.c \
	my/my_putchar.c \
	my/my_put_nbr.c \
	my/my_strcmp.c \
	my/my_strncmp.c \
	my/my_putstr.c \
	my/my_getnbr.c \
	my/my_strcpy.c \
	my/my_strcat.c \
	my/my_strncpy.c \
	my/my_strncat.c \
	my/my_revstr.c \
	my/my_strdup.c \
	my/my_isnum.c \
	my/my_str_to_word_array.c \
	my/my_error_output.c \
	printf/my_printf.c \
	printf/my_putdouble.c \
	printf/my_putlong.c \
	printf/my_octal.c \
	printf/my_high_hexa.c \
	printf/my_low_hexa.c \
	printf/my_putptr.c \
	printf/my_binary.c \
	printf/my_nonprintable_char.c

OBJ = $(SRC:.c=.o)
.SILENT:$(OBJ)

NAME_LIB = libmy.a

all: $(NAME_LIB)

.SILENT:$(NAME_LIB)
$(NAME_LIB): $(OBJ)
	ar rc $(NAME_LIB) $(OBJ)
	rm -f $(OBJ)
	@echo "\x1b[1m\x1b[36m -> library compilation done \033[0m"

.SILENT:clean
clean:
	rm -f $(OBJ)
	@echo "\x1b[1m\x1b[36m -> lib clean done \033[0m"

.SILENT:fclean
fclean: clean
	rm -f $(NAME_LIB)
	@echo "\x1b[1m\x1b[36m -> library fclean done \033[0m"

re: fclean all
