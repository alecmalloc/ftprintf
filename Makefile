SRCS		=	writehex.c writeint.c writepercent.c writetext.c ft_printf.c

OBJS		=	${SRCS:.c=.o}

HEADERS		=	ft_printf.h

NAME		=	libftprintf.a

CFLAGS		=	-Wall -Wextra -Werror

.c.o:		${HEADERS}
			gcc ${CFLAGS} -I. -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${HEADERS}
			ar -rcs $@ $^

all:		${NAME}

clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

test:
			cc -c main.c
			cc -o print_app ${OBJS} main.c
			./print_app

re:			fclean all

.PHONY:		all clean fclean re
