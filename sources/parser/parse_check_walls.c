/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelle <lelle@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:05:52 by lelle             #+#    #+#             */
/*   Updated: 2021/12/04 17:05:54 by lelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	check_recurs(char **map, int i, int j, t_elements *elem)
{
	map[i][j] = elem->dir;
	if (i == 0 || i == elem->height -1 || \
		j == 0 || j == elem->width -1)
		msg_walls_err(i, j);
	if (i > 0 && i < elem->height && map[i - 1][j] == '0')
		check_recurs(map, i - 1, j, elem);
	else if (i > 0 && i < elem->height && map[i - 1][j] == 'X')
		msg_walls_err(i, j);
	if (i > 0 && i < elem->height - 1 && map[i +1][j] == '0')
		check_recurs(map, i + 1, j, elem);
	else if (i > 0 && i < elem->height - 1 && map[i +1][j] == 'X')
		msg_walls_err(i, j);
	if (j > 0 && j < elem->width && map[i][j - 1] == '0')
		check_recurs(map, i, j - 1, elem);
	else if (j > 0 && j < elem->width && map[i][j - 1] == '0')
		msg_walls_err(i, j);
	if (j > 0 && j < elem->width - 1 && map[i][j + 1] == '0')
		check_recurs(map, i, j + 1, elem);
	else if (j > 0 && j < elem->width - 1 && map[i][j + 1] == 'X')
		msg_walls_err(i, j);
	return (0);
}

void	return_old_values(char **map, t_elements *elem)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == elem->dir)
				map[i][j] = '0';
		}
	}
	map[elem->vec.y][elem->vec.x] = elem->dir;
}

void	check_walls(char **map_arr, t_elements *elem)
{
	int	i;
	int	j;

	i = elem->vec.y;
	j = elem->vec.x;
	check_recurs(map_arr, i, j, elem);
	return_old_values(map_arr, elem);
}
