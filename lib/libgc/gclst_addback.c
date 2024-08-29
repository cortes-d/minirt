/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gclst_addback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:34:35 by achappui          #+#    #+#             */
/*   Updated: 2024/08/29 13:38:29 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gclst_addback(t_gclist **lst, t_gclist *new)
{
	t_gclist	*last;

	last = *lst;
	if (!last)
		*lst = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
