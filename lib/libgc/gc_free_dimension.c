/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free_dimension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:37:57 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 13:45:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gc_free_dimension(void *ptr, unsigned short dimension)
{
	unsigned int	i;
	void			**dptr;

	if (dimension == 1)
	{
		free(ptr);
		return ;
	}
	dptr = (void **)ptr;
	i = 0;
	while (dptr[i] != NULL)
	{
		gc_free_dimension(dptr[i], dimension - 1);
		i++;
	}
	free(dptr);
}
