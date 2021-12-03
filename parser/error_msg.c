#include "../parse.h"

int msg_error(char *name)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int msg_malloc_fail(void)
{
	ft_putstr_fd("malloc fail\n", 2);
	exit(1);
}

int msg_err2(char *name, char *text)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(text, 2);
	exit(1);
}

int msg_map_last(void)
{
	ft_putstr_fd("Map must be followed after NO, \
	SO, WE, EA, F, C elements\n", 2);
	exit(1);
}

int msg_err(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}