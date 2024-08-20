/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:13:59 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 14:42:13 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gc_display(void)
{
	t_gclst			*node;
	unsigned int	i;

	i = 0;
	node = *gc_get();
	while (node)
	{
		printf(" ________________________ \n");
		printf("|Node: %-18u|\n", i);
		printf("|Dimension: %-13hu|\n", node->dimension);
		printf("|Content: %-15p|\n", node->content);
		printf("|Next: %-18p|\n", node->next);
		printf("|________________________|\n");
		node = node->next;
		i++;
	}
}
