SRCS	= ft_printf.c \
			formats/ft_print_char.c \
			formats/ft_print_pointer.c \
			formats/ft_print_string.c \
			formats/ft_print_nbr.c \
			formats/ft_print_unbr.c \
			formats/ft_tohex.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

CFLAGS 	= -Wall -Werror -Wextra

RM		= rm -rf

all:		${NAME}

${NAME}:	${OBJS}
			ar -rsc ${NAME} ${OBJS} 

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re 