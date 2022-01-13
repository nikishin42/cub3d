/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <cstarmie@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:25:59 by cstarmie          #+#    #+#             */
/*   Updated: 2022/01/05 22:26:01 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	closer()
{
	exit(1);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_terra_sky(t_cube *cube)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < (HEIGHT / 2))
				color = color_hex(cube->src->cl[0], \
				cube->src->cl[1], cube->src->cl[2]);
			else
				color = color_hex(cube->src->fl[0], \
				cube->src->fl[1], cube->src->fl[2]);
			my_mlx_pixel_put(cube->img, x, y, color);
			x++;
		}
		y++;
	}
}

int	draw_all(t_cube *cube)
{
	cube->img->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	cube->img->addr = mlx_get_data_addr(cube->img->img, \
	&cube->img->bpp, &cube->img->line_length, &cube->img->endian);
	move(cube);
	draw_terra_sky(cube);
	draw_walls(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img->img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img->img);
	return (1);
}

void	graphic(t_cube *cube)
{
	cube->coords->posx = (double)cube->hero->x + 0.5;
	cube->coords->posy = (double)cube->hero->y + 0.5;
	set_plane(cube);
	set_direction(cube);
	mlx_hook(cube->win, 17, 0, closer, NULL);
	mlx_hook(cube->win, 2, 0, key_press, cube);
	mlx_hook(cube->win, 3, 0, key_release, cube);
	mlx_loop_hook(cube->mlx, draw_all, cube);
	mlx_loop(cube->mlx);
}
