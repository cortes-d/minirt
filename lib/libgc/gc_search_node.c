/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_search_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:11:33 by achappui          #+#    #+#             */
/*   Updated: 2024/08/29 13:36:43 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_gclist	**gc_search_node(t_gclist **lst, void *content)
{
	t_gclist	*node;

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
