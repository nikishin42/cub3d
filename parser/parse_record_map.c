#include "parse.h"

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