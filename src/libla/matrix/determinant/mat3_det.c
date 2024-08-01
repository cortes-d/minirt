/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_det.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:12:43 by achappui          #+#    #+#             */
/*   Updated: 2024/08/01 14:12:43 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	mat3_det(const t_mat3 *a)
{
	t_mat2	submatrix;
	short	i;
	short	sign;
	float	det;

	sign = 1;
	i = 0;
	det = 0;
	while (i < 3)
	{
		submatrix = mat3_submatrix(a, i, 0);
		det += a->data[i][0] * sign * mat2_det(&submatrix);
		sign *= -1;
		i++;
	}
	return (det);
}

/*
Alternative :
float	mat3_det(const t_mat4 *m)
{
	return (m->data[0][0] * mat4_cofactor(m, 0, 0) + \
			m->data[0][1] * mat4_cofactor(m, 0, 1) + \
			m->data[0][2] * mat3_cofactor(m, 0, 2) + \
}
*/