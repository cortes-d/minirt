/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:20:51 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 13:48:19 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gc_free(void *ptr)
{
	t_gclst	**found;
	t_gclst	*to_free;

	if (ptr == NULL)
		return ;
	found = gc_search_node(gc_get(), ptr);
	if (!found)
		return ;
	to_free = *found;
	*found = (*found)->next;
	gclst_free(to_free);
}
