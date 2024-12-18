NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g3
MLXFLAGS = -Lincludes/minilibx -lm -lmlx -L/usr/lib/X11 -lXext -lX11
LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a
LIBFT_PATH = includes/libft
MLX_PATH = includes/minilibx
SRC = 
OBJ = $(SRC:.c=.o)
OBJ_DIR = objects
INCLUDE_DIR = includes
RM = rm -f
all: $(NAME)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(LIBFT):
	make -C $(LIBFT_PATH)
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(MLXLIB):
	make -C $(MLX_PATH)
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLXFLAGS)
clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_PATH) clean
	$(RM) -r $(OBJ_DIR)
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean
re: fclean $(NAME)

.PHONY: all clean fclean re