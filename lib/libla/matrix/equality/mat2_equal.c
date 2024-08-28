/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:44:09 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:44:09 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

bool	mat2_equal(const t_mat2 a, const t_mat2 b)
{
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < M2_SIZE)
	{
		c = 0;
		while (++c < M2_SIZE)
		{
			if (!equalf(a.data[r][c], b.data[r][c]))
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}
