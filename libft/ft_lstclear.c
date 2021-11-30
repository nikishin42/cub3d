/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:26:11 by cstarmie          #+#    #+#             */
/*   Updated: 2021/04/24 00:26:14 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp1;

	if (lst)
	{
		temp = *lst;
		while (temp)
		{
			temp1 = temp->next;
			ft_lstdelone(temp, (*del));
			temp = temp1;
		}
		*lst = NULL;
	}
}
