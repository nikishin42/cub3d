/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:35:42 by cstarmie          #+#    #+#             */
/*   Updated: 2021/04/24 00:35:44 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char	*new_str;
	size_t	rev_size;

	if (!str)
		return (NULL);
	while (ft_strchr(set, *str) && *str)
		str++;
	rev_size = ft_strlen(str);
	while (ft_strchr(set, str[rev_size - 1]) && *str)
		rev_size--;
	new_str = ft_substr(str, 0, rev_size);
	return (new_str);
}
