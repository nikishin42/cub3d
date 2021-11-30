#include "parse.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	printf("%d\n", keycode);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	void		*mlx;
// 	void		*mlx_win;
// 	t_data		img;
// 	t_elements	*elements;

// 	// elements = parse(argc, argv);
// 	mlx = mlx_init();
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	// mlx_win = mlx_new_window(mlx, 1920, 1080, "cube3d");
// 	// mlx_loop(mlx); 
// 	return (0);
// }

int	closer(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "cub3d");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 555, 885, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L<<0, closer, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
