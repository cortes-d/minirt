/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_inv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:42:55 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:42:55 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat4	mat4_inv(t_mat4 a)
{
	t_mat4			res;
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
