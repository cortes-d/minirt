/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_inv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:10:17 by achappui          #+#    #+#             */
/*   Updated: 2024/08/01 11:10:17 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat4	mat4_inv(t_mat4 a)
{
	t_mat4	res;
	unsigned short	r;
	unsigned short	c;

	r = -1;
	while (++r < M4_SIZE)
	{
		c = -1;
		while (++c < M4_SIZE)
			res.data[r][c] = mat4_cofactor(a, r, c);
	}
	res = mat4_transpose(res);
	res = mat4_div(res, mat4_det(a));
	return (res);
}
