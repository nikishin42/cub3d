/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:27:47 by cstarmie          #+#    #+#             */
/*   Updated: 2021/04/24 00:27:51 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list_item;

	new_list_item = malloc(sizeof(t_list));
	if (!new_list_item)
		return (NULL);
	new_list_item->content = content;
	new_list_item->next = NULL;
	return (new_list_item);
}
