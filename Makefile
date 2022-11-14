SRCS	= ft_printf.c \
			ft_print_char.c \
			ft_print_pointer.c \
			ft_print_string.c \
			ft_print_unbr.c \
			ft_tohex.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

DIR_L	= libft

LIBFT	= libft.a

CC		= gcc

CFLAGS 	= -Wall -Werror -Wextra

RM		= rm -rf

all:		${NAME}

${NAME}:	${OBJS}
			make -C $(DIR_L)
			$(CC) $(DIR_L)/$(LIBFT) ${OBJS} -o ${NAME} 

clean:
			${RM} ${OBJS} && cd $(DIR_L) && make clean

fclean:		clean
			${RM} ${NAME} && cd $(DIR_L) && make fclean

re:			fclean all

.PHONY:		all clean fclean re 