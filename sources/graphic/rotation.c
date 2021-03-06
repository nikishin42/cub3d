/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <cstarmie@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:26:31 by cstarmie          #+#    #+#             */
/*   Updated: 2022/01/05 22:26:33 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

void	rot_left(t_cube *cube)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->coords->dirx;
	cube->coords->dirx = cube->coords->dirx \
	* cos(RS) - cube->coords->diry * sin(RS);
	cube->coords->diry = old_dir_x * sin(RS) + cube->coords->diry * cos(RS);
	old_plane_x = cube->coords->planex;
	cube->coords->planex = cube->coords->planex \
	* cos(RS) - cube->coords->planey * sin(RS);
	cube->coords->planey = old_plane_x * sin(RS) \
	+ cube->coords->planey * cos(RS);
}

void	rot_right(t_cube *cube)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->coords->dirx;
	cube->coords->dirx = cube->coords->dirx \
	* cos(-RS) - cube->coords->diry * sin(-RS);
	cube->coords->diry = old_dir_x * sin(-RS) + cube->coords->diry * cos(-RS);
	old_plane_x = cube->coords->planex;
	cube->coords->planex = cube->coords->planex \
	* cos(-RS) - cube->coords->planey * sin(-RS);
	cube->coords->planey = old_plane_x * sin(-RS) \
	+ cube->coords->planey * cos(-RS);
}
