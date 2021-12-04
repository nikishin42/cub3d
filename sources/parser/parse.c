#include "../../include/parse.h"

int check_fd(int *fd, char *file_name)
{
	char buf;
	int len;
	char *ext;

	*fd = open(file_name, O_RDONLY);
	if (*fd < 0 || read(*fd, &buf, 0) < 0)
		msg_error(file_name);
	len = ft_strlen(file_name);
	ext = ".cub";
	if (ft_strncmp(ext, file_name + len - 4, 5) != 0)
		msg_err("Map has invalid extension\n");
	return (0);
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
		if (!sym_found(line, "01WENS ") || !ft_strlen(line) || sym_found(line, " ")) //check tab
		{
			record_elem(line, elem, &num);
			if (*map != NULL)
				empty_line += 1;
		}
		else if (sym_found(line, "01WENS "))
		{
			if (num < 6)
				msg_map_last();
			if (empty_line)
				msg_err("Empty lines in map content\n");
			record_map(line, map);
		}
		free(line);
	}
	return (*map);
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

t_elements *parse(int argc, char **argv)
{
	t_elements *elem;
	char       *map_str;
	int fd;
	char **map_arr;
	
	if (argc != 2)
		msg_err("wrong number of arguments\n");
	check_fd(&fd, argv[1]);
	elem = malloc(sizeof(t_elements));
	init_empty_elem(elem);
	map_str = NULL;
	map_str = read_map(fd, elem, &map_str);
	if (map_str == NULL)
		msg_err("Map not found\n");
	define_map_size(map_str, elem);
	map_arr = create_array2(elem);
	fill_map(map_str, map_arr, elem->width, elem->height);
	check_start_point(map_arr, elem);
	check_walls(map_arr, elem);
	free(map_str);
	elem->map = map_arr;
	close(fd);
	return (elem);
}