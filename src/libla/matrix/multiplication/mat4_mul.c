/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:40:44 by achappui          #+#    #+#             */
/*   Updated: 2024/08/01 16:40:44 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat4	mat4_mul(const t_mat4 *a, float scalar)
{
	t_mat4	res;
	short	r;
	short	c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
			res.data[r][c] = a->data[r][c] * scalar;
	}
	return (res);
}
