/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:20:51 by achappui          #+#    #+#             */
/*   Updated: 2024/08/26 14:21:11 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gc_free(void *ptr)
{
	t_list	**found;
	t_list	*to_free;

	if (ptr == NULL)
		return ;
	found = gc_search_node(gc_get(), ptr);
	if (!found)
		return ;
	to_free = *found;
	*found = (*found)->next;
	free(to_free->content);
	free(to_free);
}
