#include "../../include/parse.h"

void	ray_init(t_cube *cube, int x, t_ray *ray)
{
	ray->camerax = 2 * x / (double)WIDTH - 1;
	// printf("camx = %f\n", ray->camerax);
	ray->raydirx = cube->coords->dirx + cube->coords->planex * ray->camerax;
	// // printf("%f\n", ray->raydirx);
	// exit(0);
	ray->raydiry = cube->coords->diry + cube->coords->planey * ray->camerax;
	// printf("rdx = %f, rdy = %f\n", ray->raydirx, ray->raydiry);
	ray->mapx = (int)(cube->coords->posx);
	ray->mapy = (int)(cube->coords->posx);
	// printf("mx = %d, my = %d\n", ray->mapx, ray->mapy);
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
	// printf("mx = %d, my = %d\n", ray->mapx, ray->mapy);
}

void	step_sidedist_init(t_cube *cube, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->sidedistx = (cube->coords->posx - ray->mapx) * ray->deltadistx;
		ray->stepx = -1;
	}
	else
	{
		ray->sidedistx = (ray->mapx - cube->coords->posx + 1.0) * ray->deltadistx;
		ray->stepx = 1;
	}
	if (ray->raydiry < 0)
	{
		ray->sidedisty = (cube->coords->posy - ray->mapy) * ray->deltadisty;
		ray->stepy = -1;
	}
	else
	{
		ray->sidedisty = (ray->mapy - cube->coords->posy + 1.0) * ray->deltadisty;
		ray->stepy = 1;
	}
}

void	dda(t_cube *cube, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (cube->src->map[ray->mapy][ray->mapx] != '0')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
		// printf("side = %d\n", ray->side);
	// printf("sdx = %f\n", ray->sidedistx);
	// printf("ddx = %f\n", ray->deltadistx);
	// printf("sdy = %f\n", ray->sidedisty);
	// printf("ddy = %f\n", ray->deltadisty);
	// printf("pwd = %f\n", ray->perpwalldist);
	// exit(0);
}

void	line_height(t_cube *cube, t_ray *ray)
{
	ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawend >= HEIGHT)
		ray->drawend = HEIGHT - 1;
}

void	draw_stripe(t_cube *cube, int x, t_ray *ray)
{
	int y;

	y = ray->drawstart;
	// printf("%d %d\n", ray->drawstart, ray->drawend);
	while (y < ray->drawend)
	{
		my_mlx_pixel_put(cube->img, x, y, 0x00232323);
		y++;
	}

}

unsigned long color_hex(int r, int g, int b)
{
	return ((r<<16) | (g<<8) | b); 
}

void	wall_side(t_cube *cube, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = cube->coords->posy + ray->perpwalldist * ray->raydiry;
	else
		wall_x = cube->coords->posx + ray->perpwalldist * ray->raydirx;
	wall_x -= floor(wall_x);
	ray->texx = (int)(wall_x * (double)(TEX));
	if (ray->side == 0 && ray->raydirx > 0)
		ray->texx = TEX - ray->texx - 1;
	if (ray->side == 1 && ray->raydiry < 0)
		ray->texx = TEX - ray->texx - 1;
	ray->step = 1.0 * TEX / ray->lineheight;
	ray->texpos = (ray->drawstart - HEIGHT / 2 + ray->lineheight / 2);
	ray->texpos *= ray->step;
}

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

void	draw_walls(t_cube *cube)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		ray_init(cube, x, &ray);
		step_sidedist_init(cube, &ray);
		dda(cube, &ray);
		line_height(cube, &ray);
		// wall_side(cube, &ray);
		// texturing(cube, &ray, x);
		draw_stripe(cube, x, &ray);
		x++;
	}
}
