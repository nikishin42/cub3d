#include "libft.h"

int	ft_atoi(const char *s)
{
	int				sign;
	unsigned long	nb;

	nb = 0;
	sign = 1;
	while ((*s == 32) || (*s > 8 && *s < 14))
		s++;
	if (*s == 45 || *s == 43)
	{
		if (*s == 45)
			sign = -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		nb = nb * 10 + *s - 48;
		s++;
		if (nb > INT64_MAX && sign == -1)
			return (0);
		if (nb >= INT64_MAX && sign == 1)
			return (-1);
	}
	return (sign * nb);
}
