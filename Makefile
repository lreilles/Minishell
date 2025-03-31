NAME = minishell
SRCDIR = src
OBJDIR = obj
CC	 = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_FILES = main.c \
			minishell.c \
			signals.c \
			

SRC = $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INCLUDE = -L ./libft -lft -L ./dprintf -lftdprintf -L ./ft_printf -lftprintf

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C dprintf
	$(MAKE) -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lreadline $(INCLUDE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) -C libft clean
	$(MAKE) -C dprintf clean
	$(MAKE) -C ft_printf clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C dprintf fclean
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
