##this makefile is not MLX ready
SRCS	= ./cub3d.c ./srcs/gnl.c ./srcs/gnl_utils.c ./srcs/parserdata.c\
			./srcs/parsermap.c ./srcs/parsermap2.c ./srcs/randomutils.c \
			./srcs/split.c

OBJS	= ${SRCS:.c=.o}

NAME	= cub3D

INC		= ./includes/

CC		= clang
RM		= rm -f

FLAGS	= -Wall -Werror -Wextra -g

all:		${NAME}

.c.o:
		${CC} -I${INC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		
		${CC} ${OBJS} -I${INC} ${FLAGS} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re