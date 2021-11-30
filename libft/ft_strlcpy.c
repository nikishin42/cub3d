/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:02:27 by cstarmie          #+#    #+#             */
/*   Updated: 2021/04/17 17:02:30 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	len;

	len = 0;
	if (!src && !dst)
		return (0);
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	while (--dstsize && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}
