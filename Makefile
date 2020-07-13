NAME = ft_printf

SOURCES = ft_printf.c \
	strany.c \
	parse_format.c \
	output.c \
	utoa.c \
	ft_ftoa.c \
	binary.c \
	output_helper.c \

OBJECTS = $(subst .c,.o,$(SOURCES))

LIBFT = libft/libft.a

FLAGS = -g -Wall -Wextra #-Werror
LINKS = -I libft -L libft -l ft

MSG = \033[38;5;214m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@gcc $(OBJECTS) -o $(NAME) $(FLAGS) $(LINKS)
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
