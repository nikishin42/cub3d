#include "../parse.h"

void read_map(int fd, t_elements *elem)
{
	char *line;
	int num;
	int gnl;
	int empty_line;
	char *map;

	empty_line = 0;
	num = 0;
	gnl = 1;
	map = NULL;
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		// printf("%s len: %d num = %d\n", line, ft_strlen(line), num);
		if (!sym_found(line, "01WENS ") || !ft_strlen(line) || sym_found(line, " ")) //check tab
		{
			if (record_elem(line, elem, &num))
				msg_invalid_line(line);
			if (map != NULL)
				empty_line += 1;
		}
		else if (sym_found(line, "01WENS "))
		{
			if (num < 6)
				msg_map_last();
			if (empty_line)
				msg_map_wrong();
			record_map(line, &map);
		}
		free(line);
		line = NULL;
		if (gnl == 0)
			break;
	}
	printf("%s\n", map);
}

t_elements *parse(int argc, char **argv)
{
	t_elements *elem;
	int fd;
	int read_res;
	char buf;

	if (argc != 2)
		msg_wrong_argc();
	elem = malloc(sizeof(t_elements));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read(fd, &buf, 0) < 0) // check later
		msg_error(argv[1]);
	// printf("fd = %d\n", fd);
	init_empty_elem(elem);
	elem->direct = '0';
	read_map(fd, elem);
	close(fd);

	printf("%d\n", elem->direct);
	printf("elem walls = %s %s %s %s\n", elem->NO, elem->SO, elem->WE, elem->EA);
	printf("F[2] = %d!\n", elem->F[1]);
	printf("F[2] = %d!\n", elem->C[1]);
	return elem;
}