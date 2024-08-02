/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:26:11 by achappui          #+#    #+#             */
/*   Updated: 2024/08/02 16:13:09 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

bool	mat2_equal(const t_mat2 *a, const t_mat2 *b)
{
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < 2)
	{
		c = 0;
		while (++c < 2)
		{
			if (!equalf(a->data[r][c], b->data[r][c]))
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}