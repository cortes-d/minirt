/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_sweep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:41:14 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/19 12:51:54 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

static void	gc_free_safe(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

void	gc_sweep(void)
{
	t_list	**gc;

	gc = gc_get();
	ft_lstclear(gc, gc_free_safe);
	*gc = NULL;
}
