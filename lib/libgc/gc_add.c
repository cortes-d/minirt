/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:41:25 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/20 13:40:30 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	*gc_add(void *ptr, unsigned short dimension)
{
	t_gclst	*new_node;

	if (ptr == NULL)
		return (NULL);
	new_node = gclst_new(ptr, dimension);
	if (new_node == NULL)
	{
		gc_free_dimension(ptr, dimension);
		return (NULL);
	}
	gclst_addfront(gc_get(), new_node);
	return (ptr);
}
