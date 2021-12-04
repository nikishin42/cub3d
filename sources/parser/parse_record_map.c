#include "../../include/parse.h"


int record_map(int num, int empty_line, char *line, char **map)
{
	char *old_map;

	if (num < 6)
		msg_map_last();
	if (empty_line)
		msg_err("Empty lines in map content\n");
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


char *read_map(int fd, t_elements *elem, char **map)
{
	char *line;
	int num;
	int gnl;
	int empty_line;

	empty_line = 0;
	num = 0;
	gnl = 1;
	line = NULL;
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		if (!sym_found(line, "01WENS ") || !ft_strlen(line) || \
		sym_found(line, " ")) //check tab
		{
			record_elem(line, elem, &num);
			if (*map != NULL)
				empty_line += 1;
		}
		else if (sym_found(line, "01WENS "))			
			record_map(num, empty_line, line, map);
		free(line);
	}
	return (*map);
}