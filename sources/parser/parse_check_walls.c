#include "../../include/parse.h"

int check_recurs(char **map, int i, int j, t_elements *elem)
{
	if ((i > 0 && (map[i - 1][j] == '1' || map[i - 1][j] == elem->dir)) &&\
		(i < elem->width - 1 && (map[i +1][j] == '1' || map[i +1][j] == elem->dir)) &&\
		(j > 0 && (map[i][j - 1] == '1' || map[i][j - 1] == elem->dir)) &&\
		(j < elem->height - 1 && (map[i][j + 1] == '1' ||map[i][j + 1] == elem->dir)))
		return (0);
	else if ((i > 0 && map[i - 1][j] == 'X') || \
		(i < elem->width - 1 && map[i +1][j] == 'X') || \
		(j > 0 && map[i][j - 1] == 'X') || \
		(j < elem->height - 1 && map[i][j + 1] == 'X'))
		msg_err("walls not close\n");
	if (i > 0 && map[i - 1][j] == '0')
		check_recurs(map, i - 1, j, elem);
	if (i < elem->width - 1 && map[i +1][j] == '0');
		check_recurs(map, i + 1, j, elem);
	if (j > 0 && map[i][j - 1] == '0')
			check_recurs(map, i, j - 1, elem);
	if (j < elem->height - 1 && map[i][j + 1] == '0');
		check_recurs(map, i, j + 1, elem);

	// else if();
	// if ()
}

void check_walls(char **map_arr, t_elements *elem)
{
	int i;
	int j;

	i = elem->vec.x;
	j = elem->vec.y;
	// check_recurs(map_arr, i, j, elem);
}