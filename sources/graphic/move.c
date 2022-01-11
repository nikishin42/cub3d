/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <cstarmie@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:26:07 by cstarmie          #+#    #+#             */
/*   Updated: 2022/01/05 22:26:26 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

void	move_forward(t_cube *cube)
{
	if (cube->src->map[(int)(cube->coords->posy)] \
	[(int)(cube->coords->posx + cube->coords->dirx)] == '0')
		cube->coords->posx += MS * cube->coords->dirx;
	if (cube->src->map[(int)(cube->coords->posy + cube->coords->diry)] \
	[(int)cube->coords->posx] == '0')
		cube->coords->posy += MS * cube->coords->diry;
}

void	move_backward(t_cube *cube)
{
	if (cube->src->map[(int)cube->coords->posy] \
	[(int)(cube->coords->posx - cube->coords->dirx)] == '0')
		cube->coords->posx -= MS * cube->coords->dirx;
	if (cube->src->map[(int)(cube->coords->posy - cube->coords->diry)] \
	[(int)cube->coords->posx] == '0')
		cube->coords->posy -= MS * cube->coords->diry;
}

void	move_left(t_cube *cube)
{
	if (cube->src->map[(int)cube->coords->posy] \
	[(int)(cube->coords->posx - cube->coords->planex)] == '0')
		cube->coords->posx -= MS * cube->coords->planex;
	if (cube->src->map[(int)(cube->coords->posy - cube->coords->planey)] \
	[(int)cube->coords->posx] == '0')
		cube->coords->posy -= MS * cube->coords->planey;
}

void	move_right(t_cube *cube)
{
	if (cube->src->map[(int)cube->coords->posy] \
	[(int)(cube->coords->posx + cube->coords->planex)] == '0')
		cube->coords->posx += MS * cube->coords->planex;
	if (cube->src->map[(int)(cube->coords->posy + cube->coords->planey)] \
	[(int)cube->coords->posx] == '0')
		cube->coords->posy += MS * cube->coords->planey;
}

void	move(t_cube *cube)
{
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
