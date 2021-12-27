#include "../../include/parse.h"


void	set_plane(t_cube *cube)
{
	if (cube->hero->direction == 'E')
	{
		cube->coords->planex = 0;
		cube->coords->planey = -0.66;
	}
	if (cube->hero->direction == 'W')
	{
		cube->coords->planex = 0;
		cube->coords->planey = 0.66;
	}
	if (cube->hero->direction == 'S')
	{
		cube->coords->planex = -0.66;
		cube->coords->planey = 0;
	}
	if (cube->hero->direction == 'N')
	{
		cube->coords->planex = 0.66;
		cube->coords->planey = 0;
	}
}

void	set_direction(t_cube *cube)
{
	if (cube->hero->direction == 'E')
	{
		cube->coords->dirx = 1;
		cube->coords->diry = 0;
	}
	if (cube->hero->direction == 'W')
	{
		cube->coords->dirx = -1;
		cube->coords->diry = 0;
	}
	if (cube->hero->direction == 'S')
	{
		cube->coords->dirx = 0;
		cube->coords->diry = -1;
	}
	if (cube->hero->direction == 'N')
	{
		cube->coords->dirx = 0;
		cube->coords->diry = 1;
	}
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
				color = color_hex(cube->src->C[0], cube->src->C[1], cube->src->C[2]);
			else
				color = color_hex(cube->src->F[0], cube->src->F[1], cube->src->F[2]);
			my_mlx_pixel_put(cube->img, x, y, color);
			x++;
		}
		y++;
	}

}

int	closer(t_cube *cube)
{
	exit(1);
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
	return 1;
}

int key_press(int key, t_cube *cube)
{
	if (key == 13)
		cube->key->w = 1;
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
	set_plane(cube);
	set_direction(cube);
	mlx_hook(cube->win, 17, 0, closer, cube);
	mlx_hook(cube->win, 2, 0, key_press, cube);
	mlx_hook(cube->win, 3, 0, key_release, cube);
	mlx_loop_hook(cube->mlx, draw_all, cube);
	mlx_loop(cube->mlx);
}