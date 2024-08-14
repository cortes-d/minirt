/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:38:47 by achappui          #+#    #+#             */
/*   Updated: 2024/07/31 15:38:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat4	mat4_mat4_mul(t_mat4 a, t_mat4 b)
{
	t_mat4			res;
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < M4_SIZE)
	{
		c = 0;
		while (c < M4_SIZE)
		{
			res.data[r][c] = \
			a.data[r][0] * b.data[0][c] + \
			a.data[r][1] * b.data[1][c] + \
			a.data[r][2] * b.data[2][c] + \
			a.data[r][3] * b.data[3][c];
			c++;
		}
		r++;
	}
	return (res);
}
