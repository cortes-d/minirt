/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:36:51 by achappui          #+#    #+#             */
/*   Updated: 2024/08/05 15:15:40 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

bool	mat4_equal(t_mat4 a, t_mat4 b)
{
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < M4_SIZE)
	{
		c = 0;
		while (++c < M4_SIZE)
		{
			if (!equalf(a.data[r][c], b.data[r][c]))
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}