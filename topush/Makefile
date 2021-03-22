##this makefile is not MLX ready
NAME	= cub3D

OS		= ${shell uname -s}
SRCS	= ./cub3d.c ./srcs/gnl.c ./srcs/gnl_utils.c ./srcs/parserdata.c\
			./srcs/parsermap.c ./srcs/parsermap2.c ./srcs/randomutils.c \
			./srcs/randomutils2.c ./srcs/split.c ./srcs/cleanexit.c

OBJS	= ${SRCS:.c=.o}

MLX_L	= mlx-linux
INC		= ./includes/
CC		= clang
RM		= rm -f

FLAGS	= -Wall -Werror -Wextra -g

.c.o:
		${CC} -I${INC} -c $< -o ${<:.c=.o}

ifeq ($(OS), Linux)
all:		${NAME}

${NAME}:	mlx ${OBJS}
		${CC} ${FLAGS} ${OBJS} ${MLX_L}/libmlx_Linux.a -I${INC} -I${MLX_L} -L${MLX_L} -o ${NAME}

mlx:
		make -C ${MLX_L}

clean:
		${RM} ${OBJS}
		make clean -C ${MLX_L}

fclean:		clean
		${RM} ${NAME}

endif

re:			fclean all

.PHONY:		all clean fclean re