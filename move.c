#include "parse.h"

void	rot_left(t_cube *cube)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->coords->dirx;
	cube->coords->dirx = cube->coords->dirx * cos(RS) - cube->coords->diry * sin(RS);
	cube->coords->diry = old_dir_x * sin(RS) + cube->coords->diry * cos(RS);
	old_plane_x = cube->coords->planex;
	cube->coords->planex = cube->coords->planex * cos(RS) - cube->coords->planey * sin(RS);
	cube->coords->planey = old_plane_x * sin(RS) + cube->coords->planey * cos(RS);
}

void	rot_right(t_cube *cube)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->coords->dirx;
	cube->coords->dirx = cube->coords->dirx * cos(-RS) - cube->coords->diry * sin(-RS);
	cube->coords->diry = old_dir_x * sin(-RS) + cube->coords->diry * cos(-RS);
	old_plane_x = cube->coords->planex;
	cube->coords->planex = cube->coords->planex * cos(-RS) - cube->coords->planey * sin(-RS);
	cube->coords->planey = old_plane_x * sin(-RS) + cube->coords->planey * cos(-RS);
}

void	move_forward(t_cube *cube)
{
	// printf("in updown\n");
	if (cube->src->map[(int)(cube->coords->posy)][(int)(cube->coords->posx + cube->coords->dirx)] == '0')
		cube->coords->posx += MS * cube->coords->dirx;
	if (cube->src->map[(int)(cube->coords->posy + cube->coords->diry)][(int)cube->coords->posx] == '0')
		cube->coords->posy += MS * cube->coords->diry;
		// printf("posx = %f posy = %f\n", cube->coords->posx, cube->coords->posy);
	// draw_all(cube);
}

void	move_backward(t_cube *cube)
{
	if (cube->src->map[(int)cube->coords->posy][(int)(cube->coords->posx - cube->coords->dirx)] == '0')
		cube->coords->posx -= MS * cube->coords->dirx;
	if (cube->src->map[(int)(cube->coords->posy - cube->coords->diry)][(int)cube->coords->posx] == '0')
		cube->coords->posy -= MS * cube->coords->diry;
}

void	move_left(t_cube *cube)
{
	if (cube->src->map[(int)cube->coords->posy][(int)(cube->coords->posx - cube->coords->planex)] == '0')
		cube->coords->posx -= MS * cube->coords->planex;
	if (cube->src->map[(int)(cube->coords->posy - cube->coords->planey)][(int)cube->coords->posx] == '0')
		cube->coords->posy -= MS * cube->coords->planey;
}

void	move_right(t_cube *cube)
{
	if (cube->src->map[(int)cube->coords->posy][(int)(cube->coords->posx + cube->coords->planex)] == '0')
		cube->coords->posx += MS * cube->coords->planex;
	if (cube->src->map[(int)(cube->coords->posy + cube->coords->planey)][(int)cube->coords->posx] == '0')
		cube->coords->posy += MS * cube->coords->planey;
}

void	move(t_cube *cube)
{
	// printf("in move\n");
	if (cube->key->w)
		move_forward(cube);
	if (cube->key->s)
		move_backward(cube);
	if (cube->key->right)
		rot_right(cube);
	if (cube->key->left)
		rot_left(cube);
	if (cube->key->a)
		move_left(cube);
	if (cube->key->d)
		move_right(cube);
}