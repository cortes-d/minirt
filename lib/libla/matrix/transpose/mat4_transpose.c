/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transpose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:44:18 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:44:18 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat4	mat4_transpose(t_mat4 a)
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
