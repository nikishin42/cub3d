# SRC = graphic/*.c parser/*.c main.c 

SRC = main.c

NAME = cub3d

FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit
# SRC =	fdf.c\
# 		liner.c\
# 		fdf_utils.c\
# 		liner_utils.c\
# 		gnl/get_next_line.c\
# 		gnl/get_next_line_utils.c

# BSRC =	fdf_bonus.c\
# 		liner_bonus.c\
# 		fdf_utils_bonus.c\
# 		liner_utils_bonus.c\
# 		gnl/get_next_line.c\
# 		gnl/get_next_line_utils.c

MLX =	minilibx_opengl/libmlx.a
LIB = 	libft/libft.a
FLAGS =	-Wall -Wextra -Werror

all: $(NAME)

# $(NAME): lib mlx
# 	gcc -o $(NAME) $(SRC) $(LIB) $(MLX) $(FRAMEWORKS)
$(NAME):
	@ gcc -o $(NAME) $(SRC) $(LIB) $(MLX) $(FRAMEWORKS)
	@ echo $(NAME) compilation is OK!
	@ ./$(NAME)

lib:
	@ make -C libft/

mlx:
	@ make -C minilibx_opengl/

clean:
	@make -C minilibx_opengl/ clean
	@make -C libft/ clean

fclean: clean
	@ rm -rf $(NAME)
	@ make -C libft/ clean
	
re: fclean all


norme:
	norminette *.c */*.c *.h */*.h

.PHONY: all clean fclean re