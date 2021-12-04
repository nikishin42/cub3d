#include "../parse.h"

int	check_start_point(char **map, t_elements *elem)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				if (elem->dir != '0')
					msg_err("More than 1 start point found\n");
				elem->dir = map[i][j];
				elem->vec.x = j;
				elem->vec.y = i;
			}
		}		
	}
	if (elem->vec.x == -1 && elem->vec.y == -1)
		msg_err("Start point not found\n");
}
