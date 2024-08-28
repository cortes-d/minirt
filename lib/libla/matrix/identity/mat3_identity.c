/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_identity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:42:35 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:42:37 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat3	mat3_identity(void)
{
	t_mat3			identity_matrix;
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < M3_SIZE)
	{
		c = 0;
		while (c < M3_SIZE)
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
