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

t_mat4	mat4_mul(t_mat4 a, float scalar)
{
	t_mat4			res;
	unsigned short	r;
	unsigned short	c;

	r = -1;
	while (++r < M4_SIZE)
	{
		c = -1;
		while (++c < M4_SIZE)
			res.data[r][c] = a.data[r][c] * scalar;
	}
	return (res);
}
