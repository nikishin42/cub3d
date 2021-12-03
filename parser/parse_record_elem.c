#include "../parse.h"

void init_empty_elem(t_elements *elem)
{
	elem->NO = NULL;
	elem->SO = NULL;
	elem->WE = NULL;
	elem->EA = NULL;
	elem->F[0] = -1;
	elem->F[1] = -1;
	elem->F[2] = -1;
	elem->C[0] = -1;
	elem->C[1] = -1;
	elem->C[2] = -1;
	elem->width = 0;
	elem->height =0;
	elem->dir = '0';
}

void check_texture(char **elem_line, char **elem_name)
{
	int fd;
	char buf;
	int read_res;

	if (*elem_name != NULL)
		msg_err2(elem_line[0], ": dublicates found\n");
	if (array2_len(elem_line) != 2)
		msg_err2(elem_line[0], ": wrong number of args\n");
	fd = open(elem_line[1], O_RDONLY);
	if (fd < 0 || read(fd, &buf, 0) < 0)
	{
		write(2, elem_line[0], ft_strlen(elem_line[0]));
		write(2, ": ", 2);
		msg_error(elem_line[1]);
	}
	close(fd);
	*elem_name = ft_strdup(elem_line[1]);
}

int check_colors(char **elem_line, int *elem_values, char *elem_name)
{
	char **colors;
	int rgb;
	int i;

	i = 0;
	if (array2_len(elem_line) != 2)
		msg_err2(elem_name, ": wrong number of args\n");
	if (elem_values[0] != -1)
		msg_err2(elem_name, ": dublicates found\n");
	colors = ft_split(elem_line[1], ',');
	if (colors == NULL)
		msg_malloc_fail();
	if (array2_len(colors) != 3)
		msg_err2(elem_name, ": invalid rgb\n");
	while (i < 3)
	{
		if (!is_digitstr(colors[i]))
			msg_err2(elem_name, ": invalid rgb\n");
		elem_values[i] = ft_atoi(colors[i]);
		if (elem_values[i] < 0 || elem_values[i] > 255)
			msg_err2(elem_name, ": invalid rgb\n");
		i++;
	}
	array2_free(colors);
	return (0);
}

int record_elem(char *line, t_elements *elem, int *num)
{
	char **split_elem;

	if (ft_strlen(line) == 0 || sym_found(line, " \0"))
		return (0);
	split_elem = ft_split(line, ' ');
	if (split_elem == NULL)
		msg_malloc_fail();
	if (ft_strncmp(split_elem[0], "NO", 3) == 0)
		check_texture(split_elem, &elem->NO);
	else if (ft_strncmp(split_elem[0], "SO", 3) == 0)
		check_texture(split_elem, &elem->SO);
	else if (ft_strncmp(split_elem[0], "WE", 3) == 0)
		check_texture(split_elem, &elem->WE);
	else if (ft_strncmp(split_elem[0], "EA", 3) == 0)
		check_texture(split_elem, &elem->EA);
	else if (ft_strncmp(split_elem[0], "F", 2) == 0)
		check_colors(split_elem, elem->F, "F");
	else if (ft_strncmp(split_elem[0], "C", 2) == 0)
		check_colors(split_elem, elem->C, "C");
	else
		msg_err2(line, ": invalid line\n");
	array2_free(split_elem);
	(*num)++;
	return (0);
}
