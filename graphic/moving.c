#include "../main.h"


void	ft_plane(t_hero *hero)
{
	hero->plane.x = -hero->dir.y * (tan(85.0 * M_PI));
	hero->plane.y = hero->dir.x * (tan(85.0 * M_PI));
}

static int	ft_check_p(t_data *data, double x, double y)
{
	x = data->hero->pos.x + x;
	y = data->hero->pos.y + y;
	if (data->map[(int)y][(int)x])
		return (0);
	return (1);
}

static void	rotate_hero(t_data *data, double rot_speed)
{
	double	sin_al;
	double	cos_al;
	double	length;

	sin_al = sin(rot_speed);
	cos_al = cos(0.05);
	data->hero->dir.x = data->hero->dir.x * cos_al - data->hero->dir.y * sin_al;
	data->hero->dir.y = data->hero->dir.x * sin_al + data->hero->dir.y * cos_al;
	length = hypot(data->hero->dir.x, data->hero->dir.y);
	data->hero->dir.x = data->hero->dir.x / length;
	data->hero->dir.y = data->hero->dir.y / length;
	ft_plane(data->hero);
	data->hero->angle += rot_speed;
}

static void	move(t_data *data, double step_x, double step_y)
{
	if (!ft_check_p(data, step_x, 0))
		data->hero->pos.x += step_x;
	if (!ft_check_p(data, 0, step_y))
		data->hero->pos.y += step_y;
}

void	move_hero(t_data *data)
{
	double	step_x;
	double	step_y;

	step_x = data->hero->dir.x * 0.3;
	step_y = data->hero->dir.y * 0.3;
	if (data->key_w == 1)
		move(data, step_x, step_y);
	if (data->key_s == 1)
		move(data, -step_x, -step_y);
	if (data->key_d == 1)
		move(data, -step_y, step_x);
	if (data->key_a == 1)
		move(data, step_y, -step_x);
	if (data->key_arrow_l == 1)
		rotate_hero(data, -0.05);
	if (data->key_arrow_r == 1)
		rotate_hero(data, 0.05);
}
