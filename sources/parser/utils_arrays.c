/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arrays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelle <lelle@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:06:41 by lelle             #+#    #+#             */
/*   Updated: 2021/12/04 17:06:43 by lelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	is_digitstr(char *str)
{
	while (*str != '\0' && ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

int	sym_found(char *str, char *search)
{
	while (*str)
	{
		if (ft_strchr(search, *str) == NULL)
			return (0);
		str++;
	}
	return (1);
}
