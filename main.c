#include "parse.h"

int main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	t_elements	*elements;

	// elements = parse(argc, argv);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "cube3d");
	mlx_loop(mlx);
	return (0);
}