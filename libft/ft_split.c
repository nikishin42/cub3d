/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:31:43 by cstarmie          #+#    #+#             */
/*   Updated: 2021/04/24 00:31:45 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_value_of_strings(char const *s, char c)
{
	int	num;
	int	i;

	num = 0;
	i = -1;
	while (s[++i])
		if (s[i] != c)
			if ((i == 0) || (s[i - 1] == c))
				num++;
	return (num);
}

char	**ft_free_arr(char **arr)
{
	if (arr)
	{
		while (*arr)
		{
			free (*arr);
			*arr = NULL;
			(*arr)++;
		}
		free(arr);
		arr = NULL;
	}
	return ((char **) NULL);
}

char	**ft_write_arr(int value_str, char const *s, char c, char **arr)
{
	int	i;
	int	n_str;
	int	n_sum;

	n_str = 0;
	i = 0;
	while (n_str < value_str)
	{
		n_sum = 0;
		while (s[i] != c && s[i])
		{
			i++;
			n_sum++;
		}
		if (n_sum)
		{
			arr[n_str] = ft_substr(s, (i - n_sum), n_sum);
			if (arr[n_str] == NULL)
				return (ft_free_arr(arr));
			n_str++;
		}
		i++;
	}
	arr[n_str] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		value_str;

	if (!s)
		return (NULL);
	value_str = ft_value_of_strings(s, c);
	i = 0;
	arr = (char **)malloc(sizeof(char *) * (value_str + 1));
	if (!arr)
		return (NULL);
	arr = ft_write_arr(value_str, s, c, arr);
	return (arr);
}
