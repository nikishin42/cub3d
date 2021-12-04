#include "../parse.h"

int record_map(char *line, char **map)
{
	char *old_map;

	if (*map == NULL)
	{
		*map = ft_strdup(line);
		if (*map == NULL)
			msg_malloc_fail();
		return (0);
	}
	old_map = ft_strjoin(*map, "\n");
	*map = ft_strjoin(old_map, line);
	if (*map == NULL)
		msg_malloc_fail();
	free(old_map);
	old_map = NULL;
	return (1);
}



int check_start_point(char **map, t_elements *elem)
{
	int i;
	int j;

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
				elem->vec.x = i;
				elem->vec.y = j;
			}
		}		
	}
}
/*
int validate_map(t_elements *elem, char *map)
{
	char **map_arr;

	define_map_size(map, elem);
	map_arr = create_array2(elem);
	fill_map(map, map_arr, elem->width, elem->height);
	elem->map = map_arr;
	check_start_point(map_arr, elem);
	check_for_walls(map_arr, elem);

	// int i = 0;
	// while (map_arr[i])
	// {
	// 	printf("%s\n", map_arr[i]);
	// 	i++;
	// }
	// printf("\n");
	return (0);
}*/