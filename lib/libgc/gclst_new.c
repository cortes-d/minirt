/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gclst_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:18:04 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 14:08:39 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_gclst	*gclst_new(void *content, unsigned short dimension)
{
	t_gclst	*new_node;

	new_node = (t_gclst *)malloc(sizeof(t_gclst));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->content = content;
	new_node->dimension = dimension;
	return (new_node);
}
