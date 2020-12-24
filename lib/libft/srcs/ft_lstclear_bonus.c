/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 03:10:30 by aait-ham          #+#    #+#             */
/*   Updated: 2019/10/15 16:34:00 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list			*node;
	t_list			*tmp;

	node = *lst;
	while (node)
	{
		tmp = node;
		node = node->next;
		if (tmp->content && del)
			del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
