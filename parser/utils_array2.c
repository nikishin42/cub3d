#include "parse.h"

int array2_len(char **array2)
{
	int i;

	i = 0;
	while (array2[i])
		i++;
	return (i);
}

void array2_free(char **array2)
{
	int i;

	i = 0;
	while (array2[i] != NULL)
		free(array2[i++]);
	array2[0] = NULL;
}