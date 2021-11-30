/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:34:32 by cstarmie          #+#    #+#             */
/*   Updated: 2021/04/24 00:34:33 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && p_s2[i] != '\0' && p_s2[i] != '\0')
	{
		if (p_s1[i] != p_s2[i])
		{
			return ((p_s1[i] - p_s2[i]));
		}
		i++;
	}
	return ((p_s1[i] - p_s2[i]));
}
