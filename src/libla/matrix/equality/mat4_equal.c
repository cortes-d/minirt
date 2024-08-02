/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:36:51 by achappui          #+#    #+#             */
/*   Updated: 2024/08/02 12:34:49 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

bool	mat4_equal(const t_mat4 *a, const t_mat4 *b)
{
	short	r;
	short	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (++c < 4)
		{
			if (!equalf(a->data[r][c], b->data[r][c]))
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}