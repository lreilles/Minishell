NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJ =	ft_printf.o\
	ft_fonction.o\
	ft_fonctions.o

${NAME} : ${OBJ}
	ar crs ${NAME} ${OBJ}

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f $(NAME)

re: fclean all
