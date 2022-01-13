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
	if (cube->hero->direction == 'W')
	{
		cube->coords->dirx = 1;
		cube->coords->diry = 0;
	}
	if (cube->hero->direction == 'E')
	{
		cube->coords->dirx = -1;
		cube->coords->diry = 0;
	}
	if (cube->hero->direction == 'N')
	{
		cube->coords->dirx = 0;
		cube->coords->diry = -1;
	}
	if (cube->hero->direction == 'S')
	{
		cube->coords->dirx = 0;
		cube->coords->diry = 1;
	}
}

int	key_press(int key, t_cube *cube)
{
	if (key == 13)
		cube->key->w = 1;
	if (key == 1)
		cube->key->s = 1;
	if (key == 0)
		cube->key->a = 1;
	if (key == 2)
		cube->key->d = 1;
	if (key == 124)
		cube->key->left = 1;
	if (key == 123)
		cube->key->right = 1;
	if (key == 53)
		closer(cube);
	return (0);
}

int	key_release(int key, t_cube *cube)
{
	if (key == 13)
		cube->key->w = 0;
	if (key == 1)
		cube->key->s = 0;
	if (key == 0)
		cube->key->a = 0;
	if (key == 2)
		cube->key->d = 0;
	if (key == 124)
		cube->key->left = 0;
	if (key == 123)
		cube->key->right = 0;
	return (0);
}
