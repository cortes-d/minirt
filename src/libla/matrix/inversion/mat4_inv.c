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

t_mat4	mat4_inv(const t_mat4 *a)
{
	t_mat4	res;
	short	r;
	short	c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
			res.data[r][c] = mat4_cofactor(a, r, c);
	}
	res = mat4_transpose(&res);
	res = mat4_div(&res, mat4_det(a));
	return (res);
}
