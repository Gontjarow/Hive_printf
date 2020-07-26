NAME = libftprintf.a

SOURCES = ft_printf.c \
	strany.c          \
	parse_format.c    \
	output_string.c   \
	output_pointer.c  \
	output_float.c    \
	output_uint.c     \
	output_int.c      \
	ft_abs.c

OBJECTS = $(subst .c,.o,$(SOURCES))

LIBFT = libft/libft.a

FLAGS = -g -Wall -Wextra #-Werror
LINKS = -I libft -L libft -l ft

MSG = \033[38;5;214m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $(NAME) $(OBJECTS)
	# @libtool -static -o $(NAME) $(NAME)
	@echo "$(MSG)$(NAME) done!$(END)"

$(OBJECTS): $(LIBFT) $(SOURCES)
	@echo "$(MSG)Compiling $(NAME)...$(END)"
	@gcc $(FLAGS) -c $(SOURCES)

$(LIBFT):
	@make -C libft

clean:
	@make -C libft clean
	@rm -f $(OBJECTS)
	@echo "$(MSG)$(NAME) objects removed!$(END)"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "$(MSG)$(NAME) targets removed!$(END)"

re: fclean all

test: $(NAME)
	@echo "$(MSG)Compiling test ...$(END)"
	@gcc $(FLAGS) test.c -o FT_PRINTF -I. -L. -lftprintf -Ilibft -Llibft -lft
	@echo "$(MSG)Done!$(END)"
