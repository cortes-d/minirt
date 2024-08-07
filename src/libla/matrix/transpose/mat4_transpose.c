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

t_mat4	mat4_transpose(t_mat4 a)
{
	t_mat4	res;
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < M4_SIZE)
	{
		c = 0;
		while (c < M4_SIZE)
		{
			res.data[c][r] = a.data[r][c];
			res.data[c][r] = a.data[r][c];
			res.data[c][r] = a.data[r][c];
			res.data[c][r] = a.data[r][c];
			c++;
		}
		r++;
	}
	return (res);
}
