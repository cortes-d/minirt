/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mat_determinant.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:32:01 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/05 15:29:39 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_mat_determinant(void)
{
	t_mat4	m;
	float	m_det;
	float	test_det;

	m = mat4( \
		row4(3.14F, 7.89F, -5.67F, 2.45F), \
		row4(-1.23F, 4.56F, 8.90F, -7.34F), \
		row4(6.78F, -9.01F, 3.21F, 5.43F), \
		row4(-4.56F, 2.34F, -8.76F, 1.98F));
	m_det = 582.3434582399991F;
	test_det = mat4_det(m);
	printf("--- testing matrix determinant ---\n");
	if (equalf(test_det, m_det))
		printf("det: OK\n");
	else
		printf("det: KO\n");
}
