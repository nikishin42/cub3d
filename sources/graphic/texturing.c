#include "../../include/parse.h"

int	rgb_channel(t_texture *tex, int x, int y, int i)
{
	char			*dst;
	unsigned char	color;

	dst = tex->addr + ((y * tex->size_line) + x * (tex->bpp / 8));
	color = *(dst + i);
	return (color);
}

int	get_color(t_texture *tex, int x, int y)
{
	int	r;
	int	g;
	int	b;

	r = rgb_channel(tex, x, y, 2);
	g = rgb_channel(tex, x, y, 1);
	b = rgb_channel(tex, x, y, 0);
	return (r << 16 | g << 8 | b);
}

void	apply_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + ((y * img->line_length) + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	texturing(t_cube *cube, t_ray *ray, int x)
{
	unsigned int	color;
	int				y;

	y = ray->drawstart;
	while (y < ray->drawend)
	{
		ray->texy = (int)ray->texpos & (TEX - 1);
		ray->texpos += ray->step;
		if (ray->side == 0)
		{
			if (ray->stepx == 1)
				color = get_color(&cube->texs[1], ray->texx, ray->texy);
			else
				color = get_color(&cube->texs[0], ray->texx, ray->texy);
		}
		if (ray->side == 1)
		{
			if (ray->stepy == 1)
				color = get_color(&cube->texs[3], ray->texx, ray->texy);
			else
				color = get_color(&cube->texs[2], ray->texx, ray->texy);
		}
		apply_pixel(cube->img, x, y, color);
		y++;
	}
}
