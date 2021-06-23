SOURCE	= ft_printf.c \
					ft_parsing.c \
					ft_type_flag.c \
					ft_type_c.c \
					ft_type_s.c \
					ft_type_p.c \
					ft_type_di.c \
					ft_type_u.c \
					ft_type_xX.c \
					ft_type_percent.c \

HEADER	=	ft_printf.h libft/libft.h

OBJECTS	=	${SOURCE:.c=.o}

RM		=	rm -f

NAME	=	libftprintf.a

AR		=	ar rcs

CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c ${HEADER}
			gcc  -Ilibft -c $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
			make -C libft
			cp libft/libft.a $(NAME)
			${AR} ${NAME} ${OBJECTS}


all:		${NAME}

clean:
			make clean -C libft
			${RM} ${OBJECTS}

fclean:		clean
			make fclean -C libft
			${RM} ${NAME}

re:			fclean all

debug:		re
			gcc -g  *.c ./libft/libft.a