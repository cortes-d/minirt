/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:44:12 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:44:12 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

bool	mat3_equal(const t_mat3 a, const t_mat3 b)
{
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < M3_SIZE)
	{
		c = 0;
		while (++c < M3_SIZE)
		{
			if (!equalf(a.data[r][c], b.data[r][c]))
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}
