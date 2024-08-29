/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gclst_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:39:45 by achappui          #+#    #+#             */
/*   Updated: 2024/08/29 13:40:52 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_gclist	*gclst_new(void *content)
{
	t_gclist	*new_elem;

	new_elem = (t_gclist *)malloc(1 * sizeof(t_gclist));
	if (new_elem == NULL)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}
