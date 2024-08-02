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

t_mat4	mat4_transpose(const t_mat4 *a)
{
	t_mat4	res;
	short	r;
	short	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			res.data[c][r] = a->data[r][c];
			res.data[c][r] = a->data[r][c];
			res.data[c][r] = a->data[r][c];
			res.data[c][r] = a->data[r][c];
			c++;
		}
		r++;
	}
	return (res);
}
