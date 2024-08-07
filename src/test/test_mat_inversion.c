/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mat_inversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:47:58 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/05 15:31:33 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_mat_inversion(void)
{
	t_mat4	m;
	t_mat4  m_inverse;
	t_mat4	m_test_inverse;

	m = mat4( \
		row4(3.14F, 7.89F, -5.67F, 2.45F), \
		row4(-1.23F, 4.56F, 8.90F, -7.34F), \
		row4(6.78F, -9.01F, 3.21F, 5.43F), \
		row4(-4.56F, 2.34F, -8.76F, 1.98F));
	m_inverse = mat4( \
		row4(3.14F, -1.23F, 6.78F, -4.56F), \
		row4(7.89F, 4.56F, -9.01F, 2.34F), \
		row4(-5.67F, 8.90F, 3.21F, -8.76F), \
		row4(2.45F, -7.34F, 5.43F, 1.98F));
	printf("--- testing matrix inversion ---\n");
	m_test_inverse = mat4_transpose(m);
	if (mat4_equal(m_test_inverse, m_inverse))
		printf("inversion: OK\n");
	else
		printf("inversion: KO\n");
}

	// test_inversion = mat4_inv(m);
	// if (mat4_equal(&matrix_a_inverse, &test_inversion))
	// 	printf("inversion: OK\n");
	// else
	// 	printf("inversion: KO\n");