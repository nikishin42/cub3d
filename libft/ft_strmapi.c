/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:34:12 by cstarmie          #+#    #+#             */
/*   Updated: 2021/04/24 00:34:15 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *source, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;

	i = 0;
	if (!source)
		return (NULL);
	dest = ft_calloc(ft_strlen(source) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (source[i] != '\0')
	{
		dest[i] = (*f)(i, source[i]);
		i++;
	}
	return (dest);
}
