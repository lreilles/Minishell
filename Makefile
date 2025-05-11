NAME = minishell
SRCDIR = src
OBJDIR = obj
CC	 = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_FILES = main.c \
			minishell.c \
			signals.c \
			utils/utils_tab.c \
			utils/utils_struct.c \
			utils/utils_fds.c \
			parsing/parsing.c \
			utils/utils_split_minishell.c \
			utils/ft_strcmp.c \
			utils/ft_isspace.c \
			utils/utils_split_minishell2.c \
			parsing/verif_errors.c \
			executing/execute.c \
			parsing/creat_cmds.c \
			utils/ft_free_t_command.c \
			parsing/expand.c \
			parsing/redirection.c \
			utils/ft_counts_cmds.c \
			utils/open_files.c \
			utils/without_quotes.c \
			executing/ft_isbuiltin.c \
			built-in/ft_echo.c \
			executing/ft_parse_echo.c \
			executing/new_cmd_expand.c \
			executing/execute_cmd_execve.c \
			utils/ft_dup2.c \
			executing/ft_parse_env.c \
			built-in/ft_env.c \
			utils/ft_strjoin_with_NULL.c \
			utils/utils_expand.c \
			utils/utils_execve_path.c \
			utils/ft_wait.c \
			utils/chose_next_separator.c \
			executing/execute_cmd.c \
			executing/ft_parse_cd.c \
			executing/ft_parse_export.c \
			executing/ft_parse_exit.c \
			executing/ft_parse_unset.c \
			executing/ft_parse_pwd.c \
			built-in/ft_pwd.c \
			parsing/ft_heredoc.c \
			parsing/expand_heredoc.c \
			parsing/redirection_heredoc.c \
			utils/unlink_all_tmp.c \
			# built-in/ft_cd.c \
			built-in/ft_export.c

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
