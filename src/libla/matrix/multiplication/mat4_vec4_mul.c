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

t_vec4	mat4_vec4_mul(const t_mat4 *a, const t_vec4 *b)
{
	t_vec4	res;
	unsigned short	r;

	r = 0;
	while (r < 4)
	{
		res.data[r] = \
		a->data[r][0] * b->data[0] + \
		a->data[r][1] * b->data[1] + \
		a->data[r][2] * b->data[2] + \
		a->data[r][3] * b->data[3];
		r++;
	}
	return (res);
}
