SRC =	sources/graphic/dda.c \
		sources/graphic/draw_walls.c \
		sources/graphic/graphic1.c \
		sources/graphic/graphic2.c \
		sources/graphic/move.c \
		sources/graphic/rotation.c \
		sources/graphic/texturing.c \
		sources/parser/error_msg.c \
		sources/parser/error_msg2.c \
		sources/parser/get_next_line_utils.c \
		sources/parser/get_next_line.c \
		sources/parser/parse_check_start_point.c \
		sources/parser/parse_check_walls.c \
		sources/parser/parse_record_elem.c \
		sources/parser/parse_record_map.c \
		sources/parser/parse.c \
		sources/parser/utils_array2.c \
		sources/parser/utils_arrays.c \
		sources/main.c

NAME = cub3d

FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit
MLX =	minilibx_opengl/libmlx.a
LIB =  libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(SRC) lib mlx
	@ gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB) $(MLX) $(FRAMEWORKS)
	@ echo $(NAME) compilation is OK!

lib:
	@ make -C libft/

mlx:
	@ make -C minilibx_opengl/

clean:
	@make -C minilibx_opengl/ clean
	@make -C libft/ clean

fclean: clean
	@ rm -rf $(NAME)
	@ make -C minilibx_opengl/ fclean
	@ make -C libft/ fclean

re: fclean all


norme:
	norminette *.c */*.c *.h */*.h

.PHONY: all clean fclean re