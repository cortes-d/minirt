/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:20:51 by achappui          #+#    #+#             */
/*   Updated: 2024/08/29 13:34:17 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gc_free(void *ptr)
{
	t_gclist	**found;
	t_gclist	*to_free;

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
