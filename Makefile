# SRC = graphic/*.c parser/*.c main.c

SRC = sources/graphic/*.c sources/main.c sources/parser/*.c

NAME = cub3d

FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit

MLX =	minilibx_opengl/libmlx.a
LIB = 	libft/libft.a
# FLAGS =	-Wall -Wextra -Werror
INCLUDES = -I./minilibx_opengl -I./parser -I./libft -I./graphic -I./include

all: $(NAME)

# $(NAME): lib mlx
# 	gcc -o $(NAME) $(SRC) $(LIB) $(MLX) $(FRAMEWORKS)
#	gcc -o $(NAME) $(INCLUDES) $(SRC) $(LIB) $(MLX) $(FRAMEWORKS)
$(NAME): $(SRC)
	gcc -o cub3d -I./minilibx_opengl -I./parser -I./libft -I./graphic -I./include -L./minilibx_opengl sources/graphic/*.c sources/main.c \
	sources/parser/*.c libft/libft.a minilibx_opengl/libmlx.a -framework OpenGL -framework AppKit
	@ echo $(NAME) compilation is OK!
	@ ./$(NAME) map.cub

# gcc для Асем
# $(NAME): $(SRC)
# 	@ gcc -o $(NAME) $(SRC) $(LIB)
# 	@ echo $(NAME) compilation is OK!
# 	@ ./$(NAME)
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