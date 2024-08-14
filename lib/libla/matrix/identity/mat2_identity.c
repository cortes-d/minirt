/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2_identity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 07:43:18 by achappui          #+#    #+#             */
/*   Updated: 2024/08/05 15:16:01 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat2	mat2_identity(void)
{
	t_mat2			identity_matrix;
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < M2_SIZE)
	{
		c = 0;
		while (c < M2_SIZE)
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