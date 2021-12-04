// #include "graphic.h"
#include "../../include/parse.h"


void	set_plane(t_cube *cube)
{
	// if (cube->hero->direction == 'E')
	// {
		cube->coords->planex = 0;
		cube->coords->planey = -0.66;
	// }
}

void	set_direction(t_cube *cube)
{
	// if (cube->hero->direction == 'E')
	// {
		cube->coords->dirx = 1;
		cube->coords->diry = 0;
	// }
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_terra_sky(t_cube *cube)
{
	int x = 0;
	int y = 0;
	int color;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < (HEIGHT / 2))
				color = 0x00b5b9ff;
				// color = 0x00b5b9ff + (y * x);
			else
				// color = 0x00ffffd1 - (y * y % 128);
				color = 0x00ffffd1;
			my_mlx_pixel_put(cube->img, x, y, color);
			x++;
		}
		y++;
	}

}

int	closer(t_cube *cube)
{
	exit(0);
}

int	draw_all(t_cube *cube)
{
	cube->img->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	cube->img->addr = mlx_get_data_addr(cube->img->img, &cube->img->bpp, &cube->img->line_length, &cube->img->endian);
	move(cube);
	draw_terra_sky(cube);
	draw_walls(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img->img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img->img);
	// mlx_do_sync(cube->mlx);
	return 1;
}

int key_press(int key, t_cube *cube)
{
	// printf("%d\n", key);
	if (key == 13)
		cube->key->w = 1;
		// up_down(cube, 0.05);
	if (key == 1)
		cube->key->s = 1;
	if (key == 0)
		cube->key->a = 1;
	if (key == 2)
		cube->key->d = 1;
	if (key == 123)
		cube->key->left = 1;
	if (key == 124)
		cube->key->right = 1;
	if (key == 53)
		closer(cube);
	return (0);
}

int key_release(int key, t_cube *cube)
{
	if (key == 13)
		cube->key->w = 0;
	if (key == 1)
		cube->key->s = 0;
	if (key == 0)
		cube->key->a = 0;
	if (key == 2)
		cube->key->d = 0;
	if (key == 123)
		cube->key->left = 0;
	if (key == 124)
		cube->key->right = 0;
	return (0);
}


void	graphic(t_cube *cube)
{
	cube->coords->posx = (double)cube->hero->x + 0.5;
	cube->coords->posy = (double)cube->hero->y + 0.5;
	// printf("x = %f, y = %f\n", cube->coords->posx, cube->coords->posy);
	set_plane(cube);
	// printf("px = %f, py = %f\n", cube->coords->planex, cube->coords->planey);
	set_direction(cube);
	// printf("dx = %f, dy = %f\n", cube->coords->dirx, cube->coords->diry);
	// cube->src->map[cube->hero->y][cube->hero->x] = '0';
	// draw_all(cube);
	mlx_hook(cube->win, 17, 0, closer, cube);
	mlx_hook(cube->win, 2, 0, key_press, cube);
	mlx_hook(cube->win, 3, 0, key_release, cube);
	mlx_loop_hook(cube->mlx, draw_all, cube);
	mlx_loop(cube->mlx);
}