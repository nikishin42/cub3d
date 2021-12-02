#include "../parse.h"

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

t_elements *parse(int argc, char **argv)
{
	t_elements *elem;
	char       *map;
	int fd;

	if (argc != 2)
		msg_err("wrong number of arguments\n");
	check_fd(&fd, argv[1]);
	elem = malloc(sizeof(t_elements));
	init_empty_elem(elem);
	map = NULL;
	map = read_map(fd, elem, &map);
	if (map == NULL)
		msg_err("Map not found\n");
	// printf("%s\n", map);
	validate_map(elem, map);

	free(map);
	close(fd);
	return (elem);
}