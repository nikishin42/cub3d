#include "main.h"

void init_null_walls(t_elements *elem)
{
	elem->NO = NULL;
	elem->SO = NULL;
	elem->WE = NULL;
	elem->EA = NULL;
}

t_elements *parse(int argc, char **argv)
{
	t_elements *elem;
	int			fd;
	

	if (argc != 2)
		msg_wrong_argc();
	elem = malloc(sizeof(t_elements));
	fd = _exists();
	init_null_walls(elem);
	elem->direct = '0';
	

	printf("%d\n", elem->direct);
	printf("elem walls = %s %s %s %s\n", elem->NO, elem->SO, elem->WE, elem->EA);
	// printf("F[2] = %d!\n", elem->F[2]);
	return elem;
}