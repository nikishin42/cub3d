/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:34:50 by cstarmie          #+#    #+#             */
/*   Updated: 2021/04/24 00:34:53 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_needle_equal(const char *s1, const char *s2, int len)
{
	while (*s2)
	{
		if (*s1 != *s2 || len == 0)
			return (0);
		s1++;
		s2++;
		len--;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == 0)
		return ((char *)haystack);
	while (len && *haystack)
	{
		if (is_needle_equal(haystack, needle, len) == 1)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
