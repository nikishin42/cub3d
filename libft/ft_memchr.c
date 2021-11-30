/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:29:28 by cstarmie          #+#    #+#             */
/*   Updated: 2021/04/24 00:29:30 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dst, int c, size_t i)
{
	int	a;

	a = (int)i;
	while (i > 0)
	{
		if (*(const unsigned char *)dst == (unsigned char)c)
			return ((char *)dst);
		dst++;
		i--;
	}
	return (NULL);
}
