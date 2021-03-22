##this makefile is not MLX ready
NAME	= cub3D

OS		= ${shell uname -s}
SRCS	= ./cub3d.c ./srcs/gnl.c ./srcs/gnl_utils.c ./srcs/parserdata.c\
			./srcs/parsermap.c ./srcs/parsermap2.c ./srcs/randomutils.c \
			./srcs/randomutils2.c ./srcs/split.c ./srcs/cleanexit.c \
			./srcs/view.c ./srcs/view2.c

OBJS	= ${SRCS:.c=.o} 

MLX_L	= mlx-linux
MLX_L_PATH = ./mlx-linux/
INC		= ./includes/
CC		= clang
RM		= rm -f

FLAGS	= -Wall -Werror -Wextra -g
MLXFLAGS	= -lm -lmlx -lXext -lX11

.c.o:
		${CC} -I${INC} -c $< -o ${<:.c=.o}

ifeq ($(OS), Linux)
all:		${NAME}

${NAME}:	mlx ${OBJS}
		${CC} ${FLAGS} ${OBJS} ${MLX_L}/libmlx_Linux.a ${MLXFLAGS} -I${INC} -I${MLX_L} -L${MLX_L_PATH} -o ${NAME} 

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