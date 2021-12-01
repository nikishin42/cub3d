#include "parse.h"

int msg_wrong_argc(void)
{
	printf("wrong number of arguments\n");
	exit(1);
}

int msg_error(char *name)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int msg_wrong_elem_args(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": wrong number of args for element\n", 2);
	exit(1);
}

int msg_elem_dublicates(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": dublicates found\n", 2);
	exit(1);
}

int msg_malloc_fail(void)
{
	ft_putstr_fd("malloc fail\n", 2);
	exit(1);
}

int msg_wrong_rgb(char *name)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": invalid rgb\n", 2);
	exit(1);
}

int msg_invalid_line(char *name)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": invalid line\n", 2);
	exit(1);
}

int msg_map_last(void)
{
	ft_putstr_fd("error: map must be followed after NO, SO, WE, EA, F, C elements declared\n", 2);
	exit(1);
}

int msg_map_wrong(void)
{
	ft_putstr_fd("map should not be split by empty line\n", 2);
	exit(1);
}
