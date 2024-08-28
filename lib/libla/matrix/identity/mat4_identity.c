/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_identity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:42:29 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:42:29 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat4	mat4_identity(void)
{
	t_mat4			identity_matrix;
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < M4_SIZE)
	{
		c = 0;
		while (c < M4_SIZE)
		{
			if (r == c)
				identity_matrix.data[r][c] = 1;
			else
				identity_matrix.data[r][c] = 0;
			c++;
		}
		r++;
	}
	return (identity_matrix);
}
