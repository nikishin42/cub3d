#include "../parse.h"

void	up_down(t_cube *cube, float ms)
{
	// printf("in updown\n");
	if (cube->src->map[(int)(cube->coords->posy)][(int)cube->coords->posx + (int)cube->coords->diry] == '0')
		cube->coords->posx += ms * cube->coords->dirx;
	if (cube->src->map[(int)(cube->coords->posy + cube->coords->diry)][(int)cube->coords->posx] == '0')
		cube->coords->posy += ms * cube->coords->diry;
		// printf("posx = %f posy = %f\n", cube->coords->posx, cube->coords->posy);
}

void	move(t_cube *cube)
{
	// printf("in move\n");
	if (cube->key->w)
		up_down(cube, 0.05);
	if (cube->key->s)
		up_down(cube, -0.05);
}