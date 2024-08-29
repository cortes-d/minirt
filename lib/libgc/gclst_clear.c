/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gclst_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:36:47 by achappui          #+#    #+#             */
/*   Updated: 2024/08/29 13:38:32 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gclst_clear(t_gclist **lst, void (*del)(void *))
{
	t_gclist	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}
