#include "../parse.h"

int is_digitstr(char *str)
{
	while (*str != '\0' && ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

int sym_found(char *str, char *search)
{
	// printf("here 14\n");
	// printf("%s - str, %s - serch\n", str, search);
	while (*str)
	{
		if (ft_strchr(search, *str) == NULL)
		{
			// printf("here:%c-\n");
			return (0);
		}
		str++;
	}
	// printf("%s - found\n", str);
	return (1);
}