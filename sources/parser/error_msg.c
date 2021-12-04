#include "../../include/parse.h"

int msg_stderror(char *name)
{
	ft_putstr_fd("Error\n\"", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int msg_malloc_fail(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("malloc fail\n", 2);
	exit(1);
}

int msg_err2(char *name, char *text)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(text, 2);
	exit(1);
}

int msg_map_last(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Map should be last (after NO, \
	SO, WE, EA, F, C elements)\n", 2);
	exit(1);
}

int msg_err(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

int msg_walls_err(int i, int j)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Walls not closed\nLine ", 2);
	ft_putnbr_fd(i + 1, 2);
	ft_putstr_fd(", symbol ", 2);
	ft_putnbr_fd(j + 1, 2);
	write(2, "\n", 1);
	exit(1);
}