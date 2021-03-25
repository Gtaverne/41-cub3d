##this makefile is not MLX ready
NAME	= cub3D

OS		= ${shell uname -s}
SRCS	= cub3d.c srcs/gnl.c srcs/gnl_utils.c srcs/parserdata.c\
			srcs/parsermap.c srcs/parsermap2.c srcs/randomutils.c \
			srcs/randomutils2.c srcs/split.c srcs/cleanexit.c \
			srcs/view.c srcs/view2.c

OBJDIR	=	object
OBJ 	=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
CFLAGS	=	-Wall -Wextra -Werror -g#-fsanitize=address
MLX_DIR	=	mlx
MLX_LNX	=	mlx-linux
MLX		=	libmlx.dylib
BONUS	=	-D BONUS=1


ifeq ($(OS), Linux)
all: $(NAME)

$(NAME): mlx $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L ./mlx-linux -lmlx -lXext -lX11 -lm

mlx:
	make -C $(MLX_LNX)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

bonus: CFLAGS	=	-Wall -Wextra -Werror $(BONUS)

bonus: mlx $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L ./mlx-linux -lmlx -lXext -lX11 -lm

clean:
	rm -f $(OBJ)
	make clean -C $(MLX_LNX)
endif




ifeq ($(OS), Darwin)
all: $(NAME)

$(NAME): mlx $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -l $(MLX_DIR)
	install_name_tool -change $(MLX) @loader_path/$(MLX_DIR)/$(MLX) $(NAME)

mlx:
	make -C $(MLX_DIR) 

$(OBJDIR)/%.o: %.c $(MLX_DIR)/$(MLX) $(HEADER)
	$(CC) $(CFLAGS) -I $(MLX_DIR) -c $< -o $@

bonus: CFLAGS	=	-Wall -Wextra -Werror $(BONUS)

bonus: mlx $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -l $(MLX_DIR)
	install_name_tool -change $(MLX) @loader_path/$(MLX_DIR)/$(MLX) $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(MLX_DIR)
endif


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re mlx bonus