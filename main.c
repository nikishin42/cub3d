#include "parse.h"

int	main(int ac, char **av)
{
	t_elements *elem;
	elem = parse(ac, av);
	graphic(elem);
	return (0);
}
