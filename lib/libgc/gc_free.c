/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:41:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/19 16:14:00 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

static void	gc_free_rec(void *ptr, size_t dimension)
{
	size_t	i;
	void	**dptr;

	if (dimension == 1)
		free(ptr);
	else
	{
		dptr = (void **)ptr;

		i = 0;
		while (dptr[i] != NULL)
		{
			gc_free_rec(dptr[i], dimension - 1);
			i++;
		}
		free(dptr);
	}
}

void	gc_free(void *ptr)
{
	t_gc		*gc;
	t_gc_node	*current;

	gc = *gc_get();
	current = gc->ptr;
	while (current)
	{
		if (current->content == ptr)
		{
			gc_free_rec(current->content, current->dimension);
			if (current->prev)
				current->prev->next = current->next;
			else
				gc->ptr = current->next;
			if (current->next)
				current->next->prev = current->prev;
			free(current);
			return ;
		}
		current = current->next;
	}
}
