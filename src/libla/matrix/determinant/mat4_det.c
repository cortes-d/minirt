/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_det.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:12:53 by achappui          #+#    #+#             */
/*   Updated: 2024/08/01 14:12:53 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

double	mat4_det(const t_mat4 *m)
{
	return (m->data[0][0] * mat4_cofactor(m, 0, 0) + \
			m->data[0][1] * mat4_cofactor(m, 0, 1) + \
			m->data[0][2] * mat4_cofactor(m, 0, 2) + \
			m->data[0][3] * mat4_cofactor(m, 0, 3));
}

/*
double	mat4_det(const t_mat4 *a)
{
	t_mat3	submatrix;
	short	i;
	short	sign;
	double	det;

	sign = 1;
	i = 0;
	det = 0;
	while (i < 4)
	{
		submatrix = mat4_submatrix(a, i, 0);
		det += a->data[i][0] * sign * mat3_det(&submatrix);
		sign *= -1;
		i++;
	}
	return (det);
}
*/
