/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gclst_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:23:35 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 13:47:18 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gclst_clear(t_gclst **lst)
{
	t_gclst	*node;
	t_gclst	*next;

	node = *lst;
	while (node)
	{
		next = node->next;
		gclst_free(node);
		node = next;
	}
	*lst = NULL;
}
