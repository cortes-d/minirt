/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_search_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:11:33 by achappui          #+#    #+#             */
/*   Updated: 2024/08/26 14:19:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_list	**gc_search_node(t_list **lst, void *content)
{
	t_list	*node;

	if (*lst == NULL)
		return (NULL);
	if ((*lst)->content == content)
		return (lst);
	node = *lst;
	while (node->next)
	{
		if (node->next->content == content)
			return (&node->next);
		node = node->next;
	}
	return (NULL);
}
