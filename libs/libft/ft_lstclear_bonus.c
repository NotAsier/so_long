/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:35:15 by aarranz-          #+#    #+#             */
/*   Updated: 2023/05/29 09:42:00 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*temp;

	if (lst && del)
	{
		node = *lst;
		while (node)
		{	
			temp = node->next;
			del(node->content);
			free(node);
			node = temp;
		}
	}
	*lst = NULL;
}
