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

int define_map_size(char *line, t_elements *elem)
{
	int len;
	int i;

	i = 0;
	elem->width = 0;
	elem->height = 0;
	while (line[i] != '\0')
	{
		len = 0;
		while (line[i] != '\n' && line[i] != '\0')
		{
			i++;
			len++;
		}
		if (len > elem->width)
			elem->width = len;
		if (line[i] == '\n')
			i++;
		elem->height++;
	}
	return (0);
}

int check_start_point(char **map, t_elements *elem)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' ||map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (elem->direct != '0')
					msg_err("More than 1 start point found\n");
				else
				{
					elem->direct = map[i][j];
					elem->position[0] = i;
					elem->position[1] = j;
				}
			}
			j++;
		}
		i++;
	}
}

int validate_map(t_elements *elem, char *map)
{
	char **map_arr;

	define_map_size(map, elem);
	map_arr = create_array2(elem);
	// printf("x = %d y = %d\n", elem->width, elem->height);
	fill_map(map, map_arr, elem->width, elem->height);
	elem->map = map_arr;
	check_start_point(map_arr, elem);

	// int i = 0;
	// while (map_arr[i])
	// {
	// 	printf("%s\n", map_arr[i]);
	// 	i++;
	// }
	// printf("\n");
	return (0);
}