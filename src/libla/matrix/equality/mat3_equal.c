/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:26:29 by achappui          #+#    #+#             */
/*   Updated: 2024/08/02 16:13:09 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

bool	mat3_equal(const t_mat3 *a, const t_mat3 *b)
{
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < 3)
	{
		c = 0;
		while (++c < 3)
		{
			if (!equalf(a->data[r][c], b->data[r][c]))
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}