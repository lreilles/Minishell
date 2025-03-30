NAME = minishell
SRCDIR = src
OBJDIR = obj
INCDIR = include
CC	 = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_FILES =

SRC = $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INCLUDE = -L ./libft -lft -L ./fprintf -lftfprintf

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C dprintf
	$(CC) $(CFLAGS) $(OBJ) -I$(INCDIR) -Ilibft libft/libft.a -o $(NAME) -lreadline

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) -C libft clean
	$(MAKE) -C dprintf clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C dprintf fclean

re: fclean all

.PHONY: all clean fclean re
