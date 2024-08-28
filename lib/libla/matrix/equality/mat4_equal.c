/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:44:05 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:44:05 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

bool	mat4_equal(t_mat4 a, t_mat4 b)
{
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < M4_SIZE)
	{
		c = 0;
		while (++c < M4_SIZE)
		{
			if (!equalf(a.data[r][c], b.data[r][c]))
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}
