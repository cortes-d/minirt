/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:43:00 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:43:00 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat4	mat4_div(t_mat4 m, float scalar)
{
	t_mat4			res;
	unsigned short	r;
	unsigned short	c;

	r = -1;
	while (++r < M4_SIZE)
	{
		c = -1;
		while (++c < M4_SIZE)
			res.data[r][c] = m.data[r][c] / scalar;
	}
	return (res);
}
