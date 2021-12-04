#include "../parse.h"

int array2_len(char **array2)
{
	int i;

	i = 0;
	while (array2[i])
		i++;
	return (i);
}

void array2_free(char **array2)
{
	int i;

	i = 0;
	while (array2[i] != NULL)
		free(array2[i++]);
	array2[0] = NULL;
}

char **create_array2(t_elements *elem)
{
	char **array_2d;
	int i;

	i = 0;
	array_2d = malloc(sizeof(char *) * (elem->height + 1));
	if (array_2d == NULL)
		msg_malloc_fail();
	while (i < elem->height)
	{
		array_2d[i] = malloc(elem->width + 1);
		if (array_2d[i] == NULL)
			msg_malloc_fail();
		array_2d[i][elem->width] = '\0';
		i++;
	}
	array_2d[i] = NULL;
	return (array_2d);
}

void fill_map(char *map, char **map_arr, int w, int h)
{
	int i;
	int j;

	i = -1;
	while (++i < h)
	{
		j = -1;
		while (*map != '\n' && *map != '\0')
		{
			if (*map == ' ')
				map_arr[i][++j] = 'X';
			else
				map_arr[i][++j] = *map;
			map++;
		}
		if (*map == '\n' || *map == '\0')
		{
			while (++j < w)
				map_arr[i][j] = 'X';
		}
		if (*map == '\0')
			break;
		map++;
	}
}

// char **cp_array2(char **array2, t_elements *)
// {

// }