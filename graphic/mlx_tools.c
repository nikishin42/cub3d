#include "../main.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mandat->addr + (y * data->mandat->line_length + x * (data->mandat->bits / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	printf("%d\n", keycode);
	return (0);
}

int	closer(t_data *data)
{
	exit(0);
	mlx_destroy_window(data->mlx, data->win);
}
