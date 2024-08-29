/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:13:59 by achappui          #+#    #+#             */
/*   Updated: 2024/08/29 13:34:12 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gc_display(void)
{
	t_gclist		*node;
	unsigned int	i;

	i = 0;
	node = *gc_get();
	printf("First: %p\n", node);
	while (node)
	{
		printf(" ________________________ \n");
		printf("|Node: %-18u|\n", i);
		printf("|Content: %-15p|\n", node->content);
		printf("|Next: %-18p|\n", node->next);
		printf("|________________________|\n");
		node = node->next;
		i++;
	}
}
