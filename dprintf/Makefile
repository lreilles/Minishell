NAME = libftdprintf.a
SOURCES = \
	ft_dprintf.c \
	ft_dselect.c \
	ft_dputchar.c \
	ft_dputnbr.c \
	ft_dputptr.c \
	ft_dputstr.c \
	ft_dputunbr.c \
	ft_dputnbr_hexa.c \
	ft_dputhexa_upper.c \

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
