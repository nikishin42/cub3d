#include "../main.h"

void	print_terra_sky(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			if (y > RES_Y / 2)
				my_mlx_pixel_put(data, x, y, 0x00CCCC00);
			else
				my_mlx_pixel_put(data, x, y, 0x003366FF);
			x++;
		}
		y++;
	}
}

void	init_dist(t_dist *dist, t_vector ray, t_hero *hero)
{
	dist->deltadistx = fabs(1 / ray.x);
	dist->deltadisty = fabs(1 / ray.y);
	dist->x = (int)hero->pos.x;
	dist->y = (int)hero->pos.y;
	if (ray.x > 0)
	{
		dist->stepx = 1;
		dist->sidedistx = (ceil(hero->pos.x) - hero->pos.x) * dist->deltadistx;
	}
	else
	{
		dist->stepx = -1;
		dist->sidedistx = (hero->pos.x - floor(hero->pos.x)) * dist->deltadistx;
	}
	if (ray.y > 0)
	{
		dist->stepy = 1;
		dist->sidedisty = (ceil(hero->pos.y) - hero->pos.y) * dist->deltadisty;
	}
	else
	{
		dist->stepy = -1;
		dist->sidedisty = (hero->pos.y - floor(hero->pos.y)) * dist->deltadisty;
	}
}

double	find_dist(t_vector ray, t_data *data, char *side)
{
	t_dist	dist;
	int		fl;

	init_dist(&dist, ray, data->hero);
	while (!data->map[dist.y][dist.x])
	{
		if (dist.sidedistx < dist.sidedisty)
		{
			dist.sidedistx += dist.deltadistx;
			dist.x += dist.stepx;
			fl = 1;
		}
		else
		{
			dist.sidedisty += dist.deltadisty;
			dist.y += dist.stepy;
			fl = 0;
		}
	}
	if (fl)
		*side = 1;
	if (fl)
		return ((dist.x - data->hero->pos.x + (1 - dist.stepx) * 0.5) / ray.x);
	*side = 0;
	return ((dist.y - data->hero->pos.y + (1 - dist.stepy) * 0.5) / ray.y);
}

void	get_perpendicular(t_vector *perp, t_vector ray, t_data *data, int *color)
{
	double		dist;
	int		side;

	dist = find_dist(ray, data, &side);
	// dist = 2;
	if (side)
	{
		perp->x = data->hero->pos.x + dist * ray.x;
		if (ray.y > 0)
			*color = 0x00CC0066; // purpur
		else
			*color = 0x0066ffff; // blue
	}
	else
	{
		perp->x = data->hero->pos.y + dist * ray.y;
		if (ray.y > 0)
			*color = 0x00ff0000; // red
		else
			*color = 0x00009900; //green
	}
	perp->x -= floor(perp->x);
	perp->y = dist;
}

void	print_stripe(t_data *data, int x, t_vector perp, int color)
{
	int	p_x;
	int	p_y;
	int	start;
	int	finish;
	t_vector	step_pos;

	step_pos.x = (double)64 / perp.y;
	start = (RES_Y - (int)perp.y) / 2;
	if (start < 0)
		start = 0;
	finish = RES_Y - start;
	p_x = (int)((double)64 * perp.x);
	step_pos.y = (start + ((int)perp.y - RES_Y) * 0.5) * step_pos.x;
	while (start < finish)
	{
		// p_y = (int)step_pos.y & (64 - 1); 
		my_mlx_pixel_put(data, x, start, color);
		step_pos.y += step_pos.x;
		start++;
	}
}

void	print_walls(t_data *data)
{
	int	x;
	double camerax;
	// t_img		*tex;
	int			color;
	t_vector	ray;
	t_vector	perp;
	
	x = 0;
	while (x < RES_X)
	{
		camerax = ((double)x * 2) / (double)RES_X;
		ray.x = data->hero->dir.x + data->hero->plane.x * camerax;
		ray.y = data->hero->dir.y + data->hero->plane.y * camerax;
		get_perpendicular(&perp, ray, data, &color);
		perp.y = (double)RES_Y / perp.y;
		print_stripe(data, x, perp, color);
		x++;
	}
	
}

int drawer(t_data *data)
{
	move_hero(data);
	print_terra_sky(data);
	print_walls(data);
	mlx_put_image_to_window(data->mlx, data->win, data->mandat->img, 0, 0);
	return(0);
}

void	data_init(t_data *data)
{
	data->mandat = malloc(sizeof(t_img));
	data->hero = malloc(sizeof(t_hero));
	data->hero->data = data;
	data->hero->pos.x = 11;
	data->hero->pos.y = 12;
	data->hero->dir.x = 0;
	data->hero->dir.y = 0;
	data->hero->plane.x = 0;
	data->hero->plane.y = 0.7;
	data->time = 0;
	data->old_time = 0;
	data->key_w = 0;
	data->key_s = 0;
	data->key_d = 0;
	data->key_a = 0;
	data->key_arrow_l = 0;
	data->key_arrow_r = 0;
}

int graphic(void)
{
	t_data	data;

	int map[24][24] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
	data.map = map;
	// data.map = malloc(sizeof(int *) * 25 + (sizeof(int) * 25) * 25);
	data.map = malloc(sizeof(int *) * 25);

	// data.map = map;
	data.map[24] = NULL;
	int x = 0;
	while (x < 25)
		data.map[x++] = malloc(sizeof(int) * 25);
	int y = -1;
	while (++y < 24)
	{
		x = -1;
		while (++x < 24)
			data.map[y][x] = map[y][x];
		data.map[y][x] = NULL;
	}
	 y = -1;
	while (++y < 24)
	{
		x = -1;
		while (++x < 24)
			printf("%d", data.map[y][x]);
		printf("\n");
	}
	data_init(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, RES_X, RES_Y, "cub3d");
	data.mandat->img = mlx_new_image(data.mlx, RES_X, RES_Y);
	data.mandat->addr = mlx_get_data_addr(data.mandat->img, &data.mandat->bits, &data.mandat->line_length, &data.mandat->endian);
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_hook(data.win, 3, 0, key_release, &data);
	mlx_hook(data.win, 17, 0l, closer, &data);
	mlx_loop_hook(data.mlx, drawer, &data);
	mlx_loop(data.mlx);
	return (0);
}
