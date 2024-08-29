/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:28:21 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:28:31 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

static void	gc_free_dimension(void *ptr, unsigned short dimension)
{
	unsigned int	i;
	void			**dptr;

	if (dimension > 1)
	{
		dptr = (void **)ptr;
		i = 0;
		while (dptr[i] != NULL)
		{
			gc_free_dimension(dptr[i], dimension - 1);
			i++;
		}
	}
	free(ptr);
}

static void	*gc_add_dimension(void *ptr, unsigned short dimension, \
	t_list **new_nodes)
{
	t_list			*new_node;
	unsigned int	i;
	void			**dptr;

	if (dimension > 1)
	{
		dptr = (void **)ptr;
		i = -1;
		while (dptr[++i] != NULL)
			if (gc_add_dimension(dptr[i], dimension - 1, new_nodes) == NULL)
				return (NULL);
	}
	new_node = ft_lstnew(ptr);
	if (new_node == NULL)
		return (NULL);
	ft_lstadd_back(new_nodes, new_node);
	return (ptr);
}

static void	free_nothing(void *ptr)
{
	(void)ptr;
	return ;
}

void	*gc_add(void *ptr, unsigned short depth_indicator)
{
	t_list	**gc;
	t_list	*new_nodes;

	if (ptr == NULL)
		return (NULL);
	new_nodes = NULL;
	gc = gc_get();
	if (gc_add_dimension(ptr, depth_indicator, &new_nodes) == NULL)
	{
		ft_lstclear(&new_nodes, &free_nothing);
		gc_free_dimension(ptr, depth_indicator);
		return (NULL);
	}
	ft_lstadd_back(gc, new_nodes);
	return (ptr);
}
